#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class TestPrint{
public:
    TestPrint() : ptr(0), str("12345"), printCount(100) {}

    void show(int i) {
        while (0 < printCount) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return ptr % 5 == i || 0 == printCount;});
            if (printCount == 0)
                return;
            cout << "thread id: " << i << ", " << str[ptr] << ", count: " << printCount << endl;
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

int main() {
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
