#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || balance.size() < account1 ||
            account2 < 1 || balance.size() < account2)
            return false;

        if (balance[account1 - 1] < money)
            return false;

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account < 1 || balance.size() < account)
            return false;

        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account < 1 || balance.size() < account)
            return false;

        if (balance[account - 1] < money)
            return false;

        balance[account - 1] -= money;
        return true;
    }

private:
    vector<long long> balance;
};

int main() {
    cout << "--------------------" << endl;
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank bank(balance);
    cout << "" << endl;
    cout << "--------------------" << endl;
    return 0;
}
