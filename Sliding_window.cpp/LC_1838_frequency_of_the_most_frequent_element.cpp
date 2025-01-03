#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// code logic on sort and sliding window problem O(n*log(n))

int maxFrequency(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int l = 0, r = 0;
    int res = 0, total = 0;

    while (r < nums.size())
    {
        total += nums[r];

        while (nums[r] * (r - l + 1) > total + k) // when condition not true so left pointer goes right side and decrease befor values
        {
            total -= nums[l];
            l++;
        }

        res = max(res, r - l + 1);
        r++;
    }

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = maxFrequency(arr, k);
    cout << ans << endl;
    return 0;
}