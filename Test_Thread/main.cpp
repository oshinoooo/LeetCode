#include <iostream>
#include <thread>
#include <vector>

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

int test1() {
    cout << "---------------------test1()" << endl;
    TestThread object;

    vector<thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(thread(&TestThread::show, &object));

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();

    cout << "---------------------test1()" << endl;
    return 0;
}

int test2() {
    cout << "---------------------test2()" << endl;
    TestThread object;
    thread t = thread(&TestThread::show, &object);
    t.detach();
    this_thread::sleep_for(chrono::seconds(1));
    cout << "---------------------test2()" << endl;
    return 0;
}

int test3() {
    cout << "---------------------test3()" << endl;
    TestYield object;

    vector<thread> threads;
    for (int i = 0; i < 10; ++i)
        threads.push_back(thread(&TestYield::count, &object, i));

    object.setReady();

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();

    cout << "---------------------test3()" << endl;
    return 0;
}

int main() {
    cout << "---------------------main()" << endl;
//    test1();
//    test2();
//    this_thread::sleep_for(chrono::seconds(5));
    test3();
    cout << "---------------------main()" << endl;
}
