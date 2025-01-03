#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1]) // if  the same number appears twice or more, skip it to avoid duplicate results
            continue;

        // -4 -1 -1 0 1 2
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0)
            {
                res.push_back({nums[i], nums[l], nums[r]});

                while (l < r && nums[l] == nums[l + 1])
                    l++;
                while (l < r && nums[r] == nums[r - 1])
                    r--;
                l++, r--;
            }
            else if (sum < 0)
                l++;
            else
                r--;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n); // Resizing the vector before assignment
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> v;
    v = threeSum(a);

    for (auto mv : v)
    {
        for (auto val : mv)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
