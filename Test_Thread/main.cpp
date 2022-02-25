#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unistd.h>
#include <cstdlib>

using namespace std;

class TestThread {
public:
    void show() {
        lock_guard<mutex> lock(mux);
        cout << "Starting: " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Exiting : " << this_thread::get_id() << endl;
    }

private:
    mutex mux;
};

int test1() {
    cout << "----------------------------------------" << endl;
    TestThread object;

    vector<thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(thread(&TestThread::show, &object));

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();

    cout << "----------------------------------------" << endl;
    return 0;
}

int test2() {
    cout << "----------------------------------------" << endl;
    TestThread object;
    thread t = thread(&TestThread::show, &object);
    t.detach();
    this_thread::sleep_for(chrono::seconds(1));
    cout << "----------------------------------------" << endl;
    return 0;
}

class TestYield {
public:
    TestYield() {
        ready = false;
    }

    void count(int id)
    {
        while (!ready)
            this_thread::yield();

        for ( int i = 0; i < 1000000; ++i) {}

        lock_guard<std::mutex> lock(mux);
        cout << "Thread: "<< id << endl;
    }

    void setReady() {
        ready = true;
    }

private:
    mutex mux;
    atomic<bool> ready;
};

int test3() {
    cout << "----------------------------------------" << endl;
    TestYield object;

    vector<thread> threads;
    for (int i = 0; i < 10; ++i)
        threads.push_back(thread(&TestYield::count, &object, i));

    object.setReady();

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();

    cout << "----------------------------------------" << endl;
    return 0;
}

class TestPool {
public:
    void serve() {
        unique_lock<mutex> lock(m);
        conditionVariable.wait(lock, [this](){return !buffer.empty();});
        string request = buffer.front();
        buffer.pop();
        lock.unlock();

        cout << this_thread::get_id() << ": " << request << endl;

        cout << this_thread::get_id() << ": starts to sleep" << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << this_thread::get_id() << ": wakes up" << endl;
        cout << "----------------------------------------" << endl;
    }

    void request(string str) {
        unique_lock<mutex> lock(m);
        buffer.push(str);
        conditionVariable.notify_all();
    }

private:
    mutex m;
    condition_variable conditionVariable;
    queue<string> buffer;
};

void test4() {
    TestPool testPool;

    vector<thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(thread(&TestPool::serve, &testPool));

    for (int i = 0; i < 10; ++i) {
        threads.push_back(thread(&TestPool::request, &testPool, string(50, i + '0')));
        this_thread::sleep_for(chrono::seconds(3));
    }

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();
}

class TestPrint {
public:
    TestPrint() : ptr(0), str("12345"), printCount(100) {}

    void show(int i) {
        unique_lock<mutex> lock(m);
        while ((5 - i) <= printCount) {
            cv.wait(lock, [&]() {
                return ptr % 5 == i;
            });

            cout << "thread id: " << i << ", " << str[ptr] << ", count: " << printCount << endl;
            if (i == 4) cout << "========================================" << endl;

            ptr = (ptr + 1) % 5;
            --printCount;
            cv.notify_all();
        }
    }

private:
    int ptr;
    const string str;
    int printCount;
    mutex m;
    condition_variable cv;
};

int test5() {
    cout << "----------------------------------------" << endl;
    TestPrint testPrint;

    vector<thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(thread(&TestPrint::show, &testPrint, i));

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();
    cout << "----------------------------------------" << endl;
    return 0;
}

namespace CSDN {
    static const int kItemRepositorySize  = 4; // Item buffer size.
    static const int kItemsToProduce  = 10;   // How many items we plan to produce.

    struct ItemRepository {
        int item_buffer[kItemRepositorySize];
        size_t read_position;
        size_t write_position;
        size_t item_counter;
        std::mutex mtx;
        std::mutex item_counter_mtx;
        std::condition_variable repo_not_full;
        std::condition_variable repo_not_empty;
    } gItemRepository;

    typedef struct ItemRepository ItemRepository;

    void ProduceItem(ItemRepository *ir, int item)
    {
        std::unique_lock<std::mutex> lock(ir->mtx);
        while(((ir->write_position + 1) % kItemRepositorySize)
              == ir->read_position) { // item buffer is full, just wait here.
            std::cout << "Producer is waiting for an empty slot...\n";
            (ir->repo_not_full).wait(lock);
        }

        (ir->item_buffer)[ir->write_position] = item;
        (ir->write_position)++;

        if (ir->write_position == kItemRepositorySize)
            ir->write_position = 0;

        (ir->repo_not_empty).notify_all();
        lock.unlock();
    }

    int ConsumeItem(ItemRepository *ir)
    {
        int data;
        std::unique_lock<std::mutex> lock(ir->mtx);
        // item buffer is empty, just wait here.
        while(ir->write_position == ir->read_position) {
            std::cout << "Consumer is waiting for items...\n";
            (ir->repo_not_empty).wait(lock);
        }

        data = (ir->item_buffer)[ir->read_position];
        (ir->read_position)++;

        if (ir->read_position >= kItemRepositorySize)
            ir->read_position = 0;

        (ir->repo_not_full).notify_all();
        lock.unlock();

        return data;
    }

    void ProducerTask()
    {
        bool ready_to_exit = false;
        while(1) {
            sleep(1);
            std::unique_lock<std::mutex> lock(gItemRepository.item_counter_mtx);
            if (gItemRepository.item_counter < kItemsToProduce) {
                ++(gItemRepository.item_counter);
                ProduceItem(&gItemRepository, gItemRepository.item_counter);
                std::cout << "Producer thread " << std::this_thread::get_id()
                          << " is producing the " << gItemRepository.item_counter
                          << "^th item" << std::endl;
            } else ready_to_exit = true;
            lock.unlock();
            if (ready_to_exit == true) break;
        }
        std::cout << "Producer thread " << std::this_thread::get_id()
                  << " is exiting..." << std::endl;
    }

    void ConsumerTask()
    {
        static int item_consumed = 0;
        while(1) {
            sleep(1);
            ++item_consumed;
            if (item_consumed <= kItemsToProduce) {
                int item = ConsumeItem(&gItemRepository);
                std::cout << "Consumer thread " << std::this_thread::get_id()
                          << " is consuming the " << item << "^th item" << std::endl;
            } else break;
        }
        std::cout << "Consumer thread " << std::this_thread::get_id()
                  << " is exiting..." << std::endl;
    }

    void InitItemRepository(ItemRepository *ir)
    {
        ir->write_position = 0;
        ir->read_position = 0;
        ir->item_counter = 0;
    }

    int test6()
    {
        InitItemRepository(&gItemRepository);
        std::thread producer1(ProducerTask);
        std::thread producer2(ProducerTask);
        std::thread producer3(ProducerTask);
        std::thread producer4(ProducerTask);
        std::thread consumer(ConsumerTask);

        producer1.join();
        producer2.join();
        producer3.join();
        producer4.join();
        consumer.join();
    }
}

int main() {
    cout << "----------------------------------------" << endl;
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
    CSDN::test6();
    cout << "----------------------------------------" << endl;
}
