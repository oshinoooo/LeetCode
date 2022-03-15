#include <iostream>
#include <vector>
#include <set>
#include <memory>

using namespace std;

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    ~Singleton() {
        cout << "~Singleton()" << endl;
    }

private:
    Singleton() {
        cout << "Singleton()" << endl;
    }

    Singleton(const Singleton& singleton) = delete;

    Singleton& operator=(const Singleton& singleton) = delete;
};

int main() {
    Singleton::getInstance();
    Singleton::getInstance();
    Singleton::getInstance();
    Singleton::getInstance();
    return 0;
}
