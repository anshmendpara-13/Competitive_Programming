#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<int>> subsets;

void generate(vector<int> &subset, int i, vector<int> &nums, int &nn)
{

    if (i == nums.size())
    {
        int sum = accumulate(subset.begin(), subset.end(), 0);
        
        auto it = find(subset.begin(),subset.end(),sum);

        if (subset.size() == nn &&  it!=(subset.end()))
        {
            subsets.push_back(subset);
        }

        return;
    }

    // Don't include the current element
    generate(subset, i + 1, nums, nn);

    // Include the current element
    subset.push_back(nums[i]);
    generate(subset, i + 1, nums, nn);
    subset.pop_back(); // Backtrack: remove the current element
}

int main()
{
    int n, nn;
    cin >> n >> nn;

    vector<int> subset;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    generate(subset, 0, nums, nn);

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
