#include <iostream>
#include <vector>
#include <thread>

#include "ReadWriteLock.h"

using namespace std;

//写者优先
ReadWriteLock readWriteLock(false);

mutex printMutex;

void safePrint(string str, int id) {
    lock_guard<mutex> lock(printMutex);
    str[6] = id + '0';
    cout << str << endl;
}

void reader(int id) {
    readWriteLock.readLock();
    safePrint("readerX is reading...", id);
    this_thread::sleep_for(std::chrono::seconds(3));
    safePrint("readerX finish reading.", id);
    readWriteLock.readUnLock();
}

void writer(int id) {
    readWriteLock.writeLock();
    safePrint("writerX is writing...", id);
    this_thread::sleep_for(std::chrono::seconds(3));
    safePrint("writerX finish writing.", id);
    readWriteLock.writeUnLock();
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.push_back(thread(reader, i));
        threads.push_back(thread(writer, i));
    }

    for (int i = 0; i < threads.size(); ++i) {
        if(threads[i].joinable())
            threads[i].join();
    }
}
