#include <iostream>

using namespace std;

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    ~Singleton() {
//        cout << "~Singleton()" << endl;
    }

    void setNumber(int a, int b, int c) {
        num1 = a;
        num2 = b;
        num3 = c;
    }

    void showNumber() {
        cout << "a: " << num1 << " b: " << num2 << " c: " << num3 << endl;
    }

private:
    int num1;
    int num2;
    int num3;

private:
    Singleton() : num1(0), num2(0), num3(0) {
//        cout << "Singleton()" << endl;
    }

    Singleton(const Singleton&) = delete;

    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    cout << "--------------------" << endl;
    Singleton& t1 = Singleton::getInstance();
    t1.showNumber();
    t1.setNumber(1, 1, 1);
    t1.showNumber();
    cout << "--------------------" << endl;
    Singleton& t2 = Singleton::getInstance();
    t1.showNumber();
    t1.setNumber(2, 2, 2);
    t1.showNumber();
    cout << "--------------------" << endl;
    Singleton& t3 = Singleton::getInstance();
    t1.showNumber();
    t1.setNumber(3, 3, 3);
    t1.showNumber();
    cout << "--------------------" << endl;
    return 0;
}
