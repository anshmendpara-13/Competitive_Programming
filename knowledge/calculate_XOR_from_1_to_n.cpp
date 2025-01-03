#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int computeXOR(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int uni = 0;
    for (int i = 1; i <= n; i++)
    {
        uni = uni ^ i;
    }
    return uni;
}
int computeXOR_efficient(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

int main()
{
    // // Q1 calculate XOR from 1 to n --> time complexity O(n)
    int n;
    cin >> n;

    // int result = computeXOR(n);
    // cout << result << endl;

    // // Q1..efficient calculate XOR from 1 to n --> time complexity O(1)
    int result = computeXOR_efficient(n);
    cout << result << endl;

    return 0;
}