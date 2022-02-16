#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class TestThread {
public:
    TestThread() : done(false) {}

    void caller() {
        unique_lock<mutex> lock(m);
        cout << "caller starts to work" << endl;
        this_thread::sleep_for(chrono::seconds (5));
        cout << "caller's work is finished" << endl;
        done = true;
        cv.notify_all();
    }

    void waiter() {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]{return done;});
        cout << "waiter starts to work" << endl;
        this_thread::sleep_for(chrono::seconds (5));
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