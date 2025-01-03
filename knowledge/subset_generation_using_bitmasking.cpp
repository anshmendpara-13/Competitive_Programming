#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subset_ct = (1 << n);
    vector<vector<int>> subsets;

    for (int mask = 0; mask < subset_ct; mask++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}

int main()
{
    // n size array of element bitmask is 2^n-1, so we can use it to represent the number from binary representation
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> ans = subsets(nums);

    for (auto sub : ans)
    {
        for (auto key : sub)
        {
            cout << key << " ";
        }
        cout << endl;
    }

    return 0;
}