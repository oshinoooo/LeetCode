#include <iostream>
#include <memory>

using namespace std;

class Solution {
public:
    Solution() : number(0) {
        cout << "Solution()" << endl;
    }

    Solution(int _number) : number(_number) {
        cout << "Solution()" << endl;
    }

    ~Solution() {
        cout << "~Solution()" << endl;
    }

    int getNumber() {
        return number;
    }

    void setNumber(int number) {
        this->number = number;
    }

    typedef auto_ptr<Solution> SolutionAutoPtr;
    typedef unique_ptr<Solution> SolutionUniquePtr;
    typedef shared_ptr<Solution> SolutionSharedPtr;
    typedef weak_ptr<Solution> SolutionWeakPtr;

private:
    int number;
};

struct use_count {
    long shared_count_ptr;
    long weak_count_ptr;
    use_count() : shared_count_ptr(0), weak_count_ptr(0) {}
};

template<class class_type>
class my_shared_ptr {
public:
    my_shared_ptr(class_type* ptr) {
        cout << "my_shared_ptr(class_type* ptr)" << endl;
        object_ptr = ptr;
        use_count_ptr = new struct use_count();
        ++use_count_ptr->shared_count_ptr;
    }

    my_shared_ptr(const my_shared_ptr& object) {
        cout << "my_shared_ptr(const my_shared_ptr& object)" << endl;
        object_ptr = object.object_ptr;
        use_count_ptr = object.use_count_ptr;
        ++use_count_ptr->shared_count_ptr;
    }

    my_shared_ptr& operator=(const my_shared_ptr& object) {
        cout << "my_shared_ptr& operator=(const my_shared_ptr& object)" << endl;
        object_ptr = object.object_ptr;
        use_count_ptr = object.use_count_ptr;
        ++use_count_ptr->shared_count_ptr;
    }

    ~my_shared_ptr() {
        cout << "~my_shared_ptr()" << endl;
        if (--use_count_ptr->shared_count_ptr == 0) {
            cout << "delete object_ptr" << endl;
            delete object_ptr;
        }

        if (use_count_ptr->shared_count_ptr == 0 && use_count_ptr->weak_count_ptr == 0) {
            cout << "delete use_count_ptr" << endl;
            delete use_count_ptr;
        }
    }

    long use_count() {
        return use_count_ptr->shared_count_ptr;
    }

    class_type* get_object_ptr() {
        return object_ptr;
    }

private:
    class_type* object_ptr;
    struct use_count* use_count_ptr;
};

void test1() {
    {
//        my_shared_ptr<Solution> ptr1(new Solution());
//        cout << ptr1.use_count() << endl;
    }
    {
//        my_shared_ptr<Solution> ptr1(new Solution());
//        cout << ptr1.use_count() << endl;
//        my_shared_ptr<Solution> ptr2(ptr1);
//        cout << ptr1.use_count() << endl;
//        cout << ptr2.use_count() << endl;
    }
    {
        my_shared_ptr<Solution> ptr1(new Solution());
        cout << ptr1.use_count() << endl;

        my_shared_ptr<Solution> ptr2(ptr1);
        cout << ptr1.use_count() << endl;
        cout << ptr2.use_count() << endl;

        my_shared_ptr<Solution> ptr3 = ptr2;
        cout << ptr1.use_count() << endl;
        cout << ptr2.use_count() << endl;
        cout << ptr3.use_count() << endl;
    }
}

void test2() {
    my_shared_ptr<Solution> ptr1(new Solution());
    cout << ptr1.get_object_ptr()->getNumber() << endl;
    ptr1.get_object_ptr()->setNumber(100);
    cout << ptr1.get_object_ptr()->getNumber() << endl;
}

int main() {
    cout << "--------------------" << endl;
//    test1();
    test2();
    cout << "--------------------" << endl;
    return 0;
}