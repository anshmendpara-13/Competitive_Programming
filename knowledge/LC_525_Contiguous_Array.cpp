#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int findMaxLength(vector<int> &nums)
{
    int x = count(nums.begin(), nums.end(), 0);
    int y = count(nums.begin(), nums.end(), 1);

    map<int, int> mp;
    int mlen = 0;
    int sum = 0;

    mp[0] = -1;

    for (int i = 0; i < nums.size(); ++i)
    {

        sum += (nums[i] == 1) ? 1 : -1;

        if (mp.find(sum) != mp.end())
        {
            mlen = max(mlen, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        } 
        // cout << sum << endl;
    }

    // for (auto val : mp)
    // {
    //     cout << val.first << " " << val.second << endl;
    // }
    // cout << mlen << endl; 

    return mlen;
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

    int ans = findMaxLength(v);
    cout << ans << endl;

    return 0;
}