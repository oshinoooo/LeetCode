#include <iostream>
#include <memory>

using namespace std;

class Solution {
public:
    Solution() {
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

#include "A.h"
#include "B.h"

int main() {
    cout << "--------------------" << endl;
/*    {
        Solution::SolutionAutoPtr p1(new Solution());
        Solution::SolutionAutoPtr p2 = s1;
        cout << p2->getNumber() << endl;
        cout << p1->getNumber() << endl;
    }
    {
        Solution::SolutionUniquePtr p1(new Solution());
        Solution::SolutionUniquePtr p2 = s1;
        cout << p2->getNumber() << endl;
        cout << p1->getNumber() << endl;
    }
    {
        Solution::SolutionSharedPtr p1(new Solution());
        Solution::SolutionSharedPtr p2 = s1;
        cout << p1->getNumber() << endl;
        cout << p2->getNumber() << endl;
    }
    {
        Solution::SolutionSharedPtr p1(new Solution());
        Solution::SolutionWeakPtr p2 = p1;
        cout << p2.use_count() << endl;
        cout << p2.lock()->getNumber() << endl;
    }*/
    {
        A::APtr a(new A());
        B::BPtr b(new B());
        a->ptr = b;
        b->ptr = a;
    }
    cout << "--------------------" << endl;
    return 0;
}
