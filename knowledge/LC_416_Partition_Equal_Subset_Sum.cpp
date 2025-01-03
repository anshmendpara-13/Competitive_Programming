#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int dp[207][20007];

int func(int i, int sum, vector<int> &nums)
{
    if (sum == 0)
        return true;

    if (i < 0)
        return false;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    // Not consider ith index
    bool ispossible = func(i - 1, sum, nums);

    // consider ith index
    if (sum - nums[i] >= 0)
        ispossible |= func(i - 1, sum - nums[i], nums);

    return dp[i][sum] = ispossible;
}

bool canPartition(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return false;
    sum = sum / 2;

    return func(nums.size() - 1, sum, nums);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << canPartition(v) << endl;

    return 0;
}