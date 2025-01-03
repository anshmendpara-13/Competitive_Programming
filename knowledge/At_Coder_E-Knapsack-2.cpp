#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 105;
int wt[N], val[N];
ll dp[N][100005];

ll func(int index, int value_left)
{
    if (value_left == 0)
        return 0;
    if (index < 0)
        return 1e15;
    if (dp[index][value_left] != -1)
        return dp[index][value_left];

    // Don't choose
    ll ans = func(index - 1, value_left);

    // Choose
    if (value_left - val[index] >= 0)
        ans = min(ans, func(index - 1, value_left - val[index]) + wt[index]);

    return dp[index][value_left] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    int max_value = 1e5;
    for (int i = max_value; i >= 0; i--)
    {
        if (func(n - 1, i) <= w)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
