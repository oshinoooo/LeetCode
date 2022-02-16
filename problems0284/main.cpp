#include <iostream>
#include <vector>

using namespace std;

class Iterator
{
public:
    Iterator(const vector<int>& nums)
    {
        Data.insert(Data.end(), nums, begin(), nums.end());
    }

    Iterator(const Iterator& iter)
    {

    }

    int next()
    {

    }

    bool hasNext() const
    {

    }

private:
    const vector<int> Data;
};

class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums)
    {
        has_next = Iterator::hasNext();
        if (has_next)
            next_data = Iterator::next();
    }

    int peek()
    {
        return next_data;
    }

    int next()
    {
        int ret = next_data;
        has_next = Iterator::hasNext();
        if (has_next)
            next_data = Iterator::next();
        return ret;
    }

    bool hasNext() const
    {
        return has_next;
    }

private:
    int next_data;
    bool has_next;
};

int main()
{
    cout << "---------------------" << endl;
    PeekingIterator itr({1, 2, 3});
    cout << itr.next() << endl;
    cout << itr.peek() << endl;
    cout << itr.next() << endl;
    cout << itr.next() << endl;
    cout << itr.hasNext() << endl;
    cout << "---------------------" << endl;
    return 0;
}
