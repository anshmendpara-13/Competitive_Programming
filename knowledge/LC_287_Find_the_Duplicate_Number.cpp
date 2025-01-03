#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int findDuplicate(vector<int> &nums)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    vector<pair<int, int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; });

    return vec[0].first;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << findDuplicate(a) << endl;

    // cout <<  <<endl;
    return 0;
}