#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

set<vector<int>> subsets;

void generate(vector<int> subset, int i, vector<int> &nums)
{

    if (i == nums.size())
    {
        sort(subset.begin(), subset.end());
        subsets.insert(subset);
        return;
    }

    // Don't include the current element
    generate(subset, i + 1, nums);

    // Include the current element
    subset.push_back(nums[i]);
    generate(subset, i + 1, nums);
    subset.pop_back(); // Backtrack: remove the current element
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

    return 0;
}
