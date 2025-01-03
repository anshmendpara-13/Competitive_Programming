#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 5;
int dp[307][10007];

int func(int index, int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;
    if (index < 0)
        return 0;
    if (dp[index][amount] != -1)
        return dp[index][amount];

    int ways = 0;
    for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[index])
    {
        ways += func(index - 1, amount - coin_amount, coins);
    }

    return dp[index][amount] = ways;
}

int change(int amount, vector<int> &coins)
{
    memset(dp, -1, sizeof(dp));
    int ans = func(coins.size() - 1, amount, coins);
    return ans;
}

int main()
{
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