//
// Created by LYL on 2022/2/23.
//

#ifndef TEST_READWRITELOCK_READWRITELOCK_H
#define TEST_READWRITELOCK_READWRITELOCK_H

#include <mutex>
#include <condition_variable>

using namespace std;

class ReadWriteLock {
public:
    ReadWriteLock(bool isPreferWriter = false) : preferWriter(isPreferWriter) {}

    void readLock() {
        unique_lock<mutex>lock(mx);
        ++readWaiting;
        cond.wait(lock, [&]() {return writing <= 0 && (!preferWriter || writeWaiting <= 0); });
        ++reading;
        --readWaiting;
    }

    void readUnLock() {
        unique_lock<mutex>lock(mx);
        --reading;
        if(reading<=0)
            cond.notify_one();
    }

    void writeLock() {
        unique_lock<mutex>lock(mx);
        ++writeWaiting;
        cond.wait(lock, [&]() {return reading <= 0 && writing <= 0; });
        ++writing;
        --writeWaiting;
    }

    void writeUnLock() {
        unique_lock<mutex>lock(mx);
        --writing;
        cond.notify_all();
    }

private:
    int readWaiting = 0;
    int writeWaiting = 0;
    int reading = 0;
    int writing = 0;

    bool preferWriter;

    mutex mx;
    condition_variable cond;
};

#endif //TEST_READWRITELOCK_READWRITELOCK_H
