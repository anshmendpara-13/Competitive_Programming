/*LC_300*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 1e5 + 7;
vector<int> a(N);

int dp[N];

int lis(int i)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[i] > a[j])
        {
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i] = ans;
}

// time  complexity O(n^2)

int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lis(i));
    }
    cout << ans << endl;

    return 0;
}