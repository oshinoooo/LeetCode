#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class TestThread {
public:
    TestThread() : done(false) {}

    void caller() {
        unique_lock<mutex> lock(m);
        cout << "caller starts to work" << endl;
        for (int i = 0; i < 5; ++i) {
            this_thread::sleep_for(chrono::seconds (1));
            cout << ".";
        }
        cout << endl;
        cout << "caller's work is finished" << endl;
        done = true;
        cv.notify_all();
    }

    void waiter() {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]{return done;});
        cout << "waiter starts to work" << endl;
        for (int i = 0; i < 5; ++i) {
            this_thread::sleep_for(chrono::seconds (1));
            cout << ".";
        }
        cout << endl;
        cout << "waiter's work is finished" << endl;
    }

private:
    mutex m;
    condition_variable cv;
    bool done;
};

int main() {
    cout << "----------------------------------------" << endl;
    TestThread testThread;

    thread t2(&TestThread::waiter, &testThread);
    thread t1(&TestThread::caller, &testThread);

    t1.join();
    t2.join();
    cout << "----------------------------------------" << endl;
    return 0;
}