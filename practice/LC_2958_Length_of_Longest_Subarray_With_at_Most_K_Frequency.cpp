#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int maxSubarrayLength(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int ans = 0;
    int i = 0, j = 0;

    while (j < nums.size())
    {
        mp[nums[j]]++;

        while (i <= j && mp[nums[j]] > k)
        {
            mp[nums[i]]--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
    
}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << maxSubarrayLength(v, k) << endl;

    return 0;
}