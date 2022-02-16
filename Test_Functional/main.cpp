#include <iostream>
#include <functional>

using namespace std;

int main() {
    cout << "--------------------" << endl;
    function<string (string, string)> func;
    func = [&](string str1, string str2) {
        return str1 + str2;
    };
    cout << func("123", "456") << endl;
    cout << "--------------------" << endl;
    return 0;
}
