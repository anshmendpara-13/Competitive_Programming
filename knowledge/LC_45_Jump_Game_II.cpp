#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int jump(vector<int> &nums)
{

    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] = max(nums[i] + i, nums[i - 1]);
    }

    int ind = 0, ans = 0;

    while (ind < nums.size() - 1)
    {
        ans++;
        ind = nums[ind];
    }

    return ans;
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

    int ans = jump(v);
    cout << ans << endl;

    return 0;
}