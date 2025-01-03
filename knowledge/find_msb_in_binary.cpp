#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int setbitnumber(int n)
{
    int k = __builtin_clz(n); // count the number of leading zeros in
    return 1 << (31 - k);
}

int setbitnumber_easy(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int msb = 0;
    n = n / 2;
    while (n != 0)
    {
        n = n / 2;
        msb++;
    }
    return (1 << msb);
}
int main()
{
    // int n;
    // cin >> n;
    // int ans = setbitnumber(n); // time complexity O(1)
    // cout << ans << endl;

    // // n = ~(int)0; // test for possible overflow
    // // cout << (unsigned int)setbitnumber(n) << endl;

    // OR *************************** simple method but time complexity O(log N)

    int n;
    cin >> n;

    cout << setbitnumber_easy(n) << endl;

    return 0;
}