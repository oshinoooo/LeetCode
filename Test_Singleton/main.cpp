#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>
#include <memory>
#include <mutex>

using namespace std;

// not safe lazy
class Singleton_not_safe_lazy {
public:
    static Singleton_not_safe_lazy* get_instance() {
        if(m_instance_ptr == nullptr)
            m_instance_ptr = new Singleton_not_safe_lazy;
        return m_instance_ptr;
    }

    ~Singleton_not_safe_lazy() {
        cout << "~Singleton_not_safe_lazy()" << endl;
    }

private:
    Singleton_not_safe_lazy() {
        cout << "Singleton_not_safe_lazy()" << endl;
    }

    Singleton_not_safe_lazy(Singleton_not_safe_lazy&) = delete;

    Singleton_not_safe_lazy& operator=(const Singleton_not_safe_lazy&) = delete;

private:
    static Singleton_not_safe_lazy* m_instance_ptr;
};

Singleton_not_safe_lazy* Singleton_not_safe_lazy::m_instance_ptr = nullptr;

// safe lazy 1
class Singleton_safe_lazy1 {
public:
    static Singleton_safe_lazy1* get_instance() {
        if(m_instance_ptr == nullptr) {
            std::lock_guard<std::mutex> lk(m_mutex);
            if(m_instance_ptr == nullptr)
                m_instance_ptr = new Singleton_safe_lazy1;
        }
        return m_instance_ptr;
    }

    ~Singleton_safe_lazy1() {
        cout << "~Singleton_safe_lazy1()" << endl;
    }

private:
    Singleton_safe_lazy1() {
        cout << "Singleton_safe_lazy1()" << endl;
    }

    Singleton_safe_lazy1(Singleton_safe_lazy1&) = delete;

    Singleton_safe_lazy1& operator=(const Singleton_safe_lazy1&) = delete;

private:
    static Singleton_safe_lazy1* m_instance_ptr;
    static mutex m_mutex;
};

Singleton_safe_lazy1* Singleton_safe_lazy1::m_instance_ptr = nullptr;
mutex Singleton_safe_lazy1::m_mutex;

// safe lazy 2
class Singleton_safe_lazy2 {
public:
    typedef std::shared_ptr<Singleton_safe_lazy2> Ptr;

    ~Singleton_safe_lazy2() {
        cout << "~Singleton_safe_lazy2()" << endl;
    }

    static Ptr get_instance() {
        if(m_instance_ptr == nullptr) {
            std::lock_guard<std::mutex> lk(m_mutex);
            if(m_instance_ptr == nullptr)
                m_instance_ptr = shared_ptr<Singleton_safe_lazy2>(new Singleton_safe_lazy2);
        }
        return m_instance_ptr;
    }

private:
    Singleton_safe_lazy2() {
        cout << "Singleton_safe_lazy2()" << endl;
    }

    Singleton_safe_lazy2(Singleton_safe_lazy2&) = delete;

    Singleton_safe_lazy2& operator=(const Singleton_safe_lazy2&) = delete;

private:
    static Ptr m_instance_ptr;
    static mutex m_mutex;
};

Singleton_safe_lazy2::Ptr Singleton_safe_lazy2::m_instance_ptr = nullptr;
mutex Singleton_safe_lazy2::m_mutex;

// magic static
class Singleton_magic_static {
public:
    static Singleton_magic_static& get_instance() {
        static Singleton_magic_static instance;
        return instance;
    }

    ~Singleton_magic_static() {
        cout << "~Singleton_magic_static()" << endl;
    }

private:
    Singleton_magic_static() {
        cout << "Singleton_magic_static()" << endl;
    }

    Singleton_magic_static(const Singleton_magic_static&) = delete;

    Singleton_magic_static& operator=(const Singleton_magic_static&) = delete;
};

int test1() {
    cout << "---------------------" << endl;
    {
        Singleton_not_safe_lazy* sin1 = Singleton_not_safe_lazy::get_instance();
        Singleton_not_safe_lazy* sin2 = Singleton_not_safe_lazy::get_instance();
        Singleton_not_safe_lazy* sin3 = Singleton_not_safe_lazy::get_instance();
        delete sin1;
    }
    cout << "---------------------" << endl;
    {
        Singleton_safe_lazy1* sin1 = Singleton_safe_lazy1::get_instance();
        Singleton_safe_lazy1* sin2 = Singleton_safe_lazy1::get_instance();
        Singleton_safe_lazy1* sin3 = Singleton_safe_lazy1::get_instance();
        delete sin1;
    }
    cout << "---------------------" << endl;
    {
        Singleton_safe_lazy2::Ptr sin1 = Singleton_safe_lazy2::get_instance();
        Singleton_safe_lazy2::Ptr sin2 = Singleton_safe_lazy2::get_instance();
        Singleton_safe_lazy2::Ptr sin3 = Singleton_safe_lazy2::get_instance();
    }
    cout << "---------------------" << endl;
    {
        Singleton_magic_static& sin1 = Singleton_magic_static::get_instance();
        Singleton_magic_static& sin2 = Singleton_magic_static::get_instance();
        Singleton_magic_static& sin3 = Singleton_magic_static::get_instance();
    }
    cout << "---------------------" << endl;
    return 0;
}

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

class SingletonHungry {
public:
    static SingletonHungry& getInstance() {
        return instance;
    }

    ~SingletonHungry() {
        cout << "~SingletonHungry()" << endl;
    }

private:
    SingletonHungry() {
        cout << "SingletonHungry()" << endl;
    }

    SingletonHungry(const SingletonHungry& singleton) = delete;

    SingletonHungry& operator=(const SingletonHungry& singleton) = delete;

private:
    static SingletonHungry instance;
};

SingletonHungry SingletonHungry::instance;

int test2() {
    Singleton::getInstance();
    Singleton::getInstance();
    Singleton::getInstance();
    Singleton::getInstance();
    Singleton::getInstance();

    SingletonHungry::getInstance();
    SingletonHungry::getInstance();
    SingletonHungry::getInstance();
    SingletonHungry::getInstance();
    SingletonHungry::getInstance();
}

int main() {
//    test1();
    test2();
}
