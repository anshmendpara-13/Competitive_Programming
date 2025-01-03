#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// for n element subsets are 2^n

set<vector<int>> subsets;

void generate(vector<int> &subset, int i, vector<int> &nums)
{

    // base condition

    if (i == nums.size())
    {
        subsets.insert(subset);
        return;
    }

    // ith element not in subset
    generate(subset, i + 1, nums);

    // ************* //

    // ith element consider in subset
    subset.push_back(nums[i]);

    generate(subset, i + 1, nums);
    subset.pop_back();
}
int main()
{
    int n;
    cin >> n;

    vector<int> subset;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    generate(subset, 0, nums);

    vector<vector<int>> ans;
    for (const auto &vec : subsets)
    {
        ans.push_back(vec);
    }

    for (auto subset : ans)
    {
        for (auto ele : subset)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    // cout << subsets.size() << endl;

    return 0;
}