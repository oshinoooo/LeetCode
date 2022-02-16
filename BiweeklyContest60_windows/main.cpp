#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMiddleIndex(vector<int>& nums)
    {
        int left_sum = 0, right_sum = 0;

        for (int i = 1; i < nums.size(); ++i)
            right_sum += nums[i];

        if (right_sum == 0)
            return 0;

        for (int mid = 1; mid < nums.size(); ++mid)
        {
            left_sum += nums[mid - 1];
            right_sum -= nums[mid];

            if (left_sum == right_sum)
                return mid;
        }

        if (left_sum == 0)
            return nums.size() - 1;

        return -1;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land)
    {
        vector<vector<int>> record;
        for (int i = 0; i < land.size(); ++i)
        {
            vector<int> tmp;
            for (int j = 0; j < land[0].size(); ++j)
                tmp.push_back(0);
            record.push_back(tmp);
        }

        vector<vector<int>> out;
        for (int i = 0; i < land.size(); ++i)
        {
            for (int j = 0; j < land[0].size(); ++j)
            {
                if (land[i][j] == 1 && record[i][j] == 0)
                {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);

                    for (int k = i; k < land.size(); ++k)
                    {
                        if (land[k][j] == 0)
                        {
                            tmp.push_back(--k);
                            break;
                        }

                        if (k == land.size() - 1)
                        {
                            tmp.push_back(k);
                            break;
                        }
                    }

                    for (int k = j; k < land[0].size(); ++k)
                    {
                        if (land[i][k] == 0)
                        {
                            tmp.push_back(--k);
                            break;
                        }

                        if (k == land[0].size() - 1)
                        {
                            tmp.push_back(k);
                            break;
                        }
                    }

                    for (int k = tmp[0]; k <= tmp[2]; ++k)
                        for (int l = tmp[1]; l <= tmp[3] ; ++l)
                            record[k][l] = 1;

                    out.push_back(tmp);
                }
            }
        }

        return out;
    }

    int numberOfGoodSubsets(vector<int>& nums)
    {
        return 0;
    }
};

class LockingTree
{
public:
    LockingTree(vector<int>& parent)
    {

    }

    bool lock(int num, int user)
    {

    }

    bool unlock(int num, int user)
    {

    }

    bool upgrade(int num, int user)
    {

    }
};

void Test1()
{
    cout << "----------------------" << endl;
    vector<int> in = {2, 5, 4, 3, 1, 1, 2};
    Solution s;
    cout << s.findMiddleIndex(in) << endl;
    cout << "----------------------" << endl;
};

void Test2()
{
    cout << "----------------------" << endl;
    vector<vector<int>> in = {{1, 0, 0},{0, 1, 1}, {0, 1, 1}};
    Solution s;
    vector<vector<int>> out = s.findFarmland(in);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "----------------------" << endl;
};

void Test3()
{
    cout << "----------------------" << endl;
    vector<int> in = {2, 3, -1, 8, 4};
    LockingTree lt(in);
    cout << "----------------------" << endl;
};

void Test4()
{
    cout << "----------------------" << endl;
    vector<int> in = {1, 2, 3, 4};
    Solution s;
    cout << s.numberOfGoodSubsets(in) << endl;
    cout << "----------------------" << endl;
};

int main()
{
    cout << "----------------------" << endl;
    Test1();
    Test2();
    Test3();
    Test4();
    cout << "----------------------" << endl;
    return 0;
}
