#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 5;
int dp[10007];

int func(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 0;
    if (dp[amount] != -1)
        return dp[amount];
    int ans = INT_MAX;
    for (auto coin : coins)
    {
        if (amount - coin >= 0)
            ans = min(ans + 0LL, func(amount - coin, coins) + 1LL);
    }
    return dp[amount] = ans;
}

int change(int amount, vector<int> &coins)
{
    int ans = func(amount, coins);
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    memset(dp, -1, 10007);
    int n, amount;
    cin >> n >> amount;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    cout << change(amount, v) << endl;

    return 0;
}