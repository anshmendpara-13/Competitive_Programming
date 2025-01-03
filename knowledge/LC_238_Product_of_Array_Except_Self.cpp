#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> productExceptSelf(vector<int> &nums)
{
    int x = 1;
    int cnt = 0;
    vector<int> ans(nums.size(),0);
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            cnt++;
            continue;
        }
        else
        {
            x = x * nums[i];
        }
    }
    if (cnt>1)
    {
        return ans;
    }
    
    // cout << x << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt != 0)
        {
            if (nums[i] == 0)
            {
                ans[i] = x;
            }
            else
            {
                ans[i] = 0;
            }
        }
        else
        {
            if (nums[i] == 0)
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = x / nums[i];
            }
        }
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

    vector<int> ans;
    ans = productExceptSelf(v);
    for (auto val : ans)
    {
        cout << val << " ";
    }

    // int x = accumulate(v.begin() + 1, v.end(), 0);
    // cout << x << endl;

    return 0;
}