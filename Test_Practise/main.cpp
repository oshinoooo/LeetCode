#include<bits/stdc++.h>

using namespace std;

int main() {
    cout << "----------------------------------------" << endl;
    int a[5] = {1, 2, 3, 4, 5};
    int* ptr = (int*)(&a + 1);

    cout << a << endl;
    cout << *a << endl;
    cout << *(a + 1) << endl;
    cout << &a << endl;
    cout << &a + 1 << endl;

    printf("%d, %d\n", *(a + 1), *(ptr - 1));
    cout << "----------------------------------------" << endl;
    return 0;
}
