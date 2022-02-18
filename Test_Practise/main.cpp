#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string.h>

using namespace std;

int main() {
    cout << "----------------------------------------" << endl;
    char s[20] = "hello\01234";
    cout << strlen(s) << endl;
    cout << sizeof(s) << endl;
    cout << "----------------------------------------" << endl;
    return 0;
}
