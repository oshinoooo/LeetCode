#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string.h>

using namespace std;

mutex m;

void show(int i) {
    lock_guard<mutex> lock(m);
    for (int j = 0; j < 50; ++j)
        cout << i << " ";
    cout << endl;
}

int main() {
    cout << "----------------------------------------" << endl;
    thread t1(show, 1);
    thread t2(show, 2);
    t1.join();
    t2.join();
    cout << "----------------------------------------" << endl;
    return 0;
}
