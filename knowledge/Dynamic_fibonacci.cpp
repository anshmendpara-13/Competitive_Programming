#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e3 + 7;

// 0 1 1 2 3 5 8 -> time complexity O(1 + 2 + 4 + 8 + ..... + 2^n) => O(2^n)  limit is n < 10
// using dp time complexity O(N)
// using dp O(N!) => O(2^N)

// In this problem we use top down approach

ll dp[N];

ll fib(ll n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{

    memset(dp, -1, sizeof(dp)); // initialize all elements of array with -1

    ll n;
    cin >> n;

    cout << fib(n) << endl;

    // for (auto val : dp)
    // {
    //     cout << val << endl;
    // }

    return 0;
}