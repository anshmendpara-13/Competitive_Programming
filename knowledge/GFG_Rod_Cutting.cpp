#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int dp[1005];

int func(int len, vector<int> &prices)
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int ans = 0;
    for (int len_to_cut = 1; len_to_cut < prices.size(); len_to_cut++)
    {
        if (len - len_to_cut >= 0)
            ans = max(ans, func(len - len_to_cut, prices) + prices[len_to_cut - 1]);
    }
    return dp[len] = ans;
}

int cutRod(int price[], int n)
{
    vector<int> prices(price, price + n);
    return func(n, prices);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << cutRod(arr, n) << endl;

    return 0;
}