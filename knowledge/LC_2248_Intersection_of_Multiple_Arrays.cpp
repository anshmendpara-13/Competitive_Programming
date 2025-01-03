#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> intersection(vector<vector<int>> &nums)
{
    map<int, int> mp;
    int size = nums.size();
    set<int> st;
    vector<int> ans;
    for (auto sn : nums)
    {
        for (auto n : sn)
        {
            mp[n]++;
        }
    }

    for (auto v : mp)
    {
        if (v.second == size)
        {
            st.insert(v.first);
        }
    }

    for (auto i : st)
    {
        ans.push_back(i);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums;
    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;
        vector<int> temp(size);
        for (int j = 0; j < size; j++)
        {
            cin >> temp[j];
        }
        nums.push_back(temp);
    }

    vector<int> ans = intersection(nums);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}