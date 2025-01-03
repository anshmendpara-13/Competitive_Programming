#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool canJump(vector<int> &nums)
{
    int initial = nums[0];

    for (int i = 0; i < nums.size(); ++i)
    {
        if (initial >= nums.size() - 1)
        {
            return true;
        }

        if (nums[i] == 0 and initial == i)
        {
            return false;
        }

        if (i + nums[i] > initial)
        {
            initial = i + nums[i];
        }
    }

    return true;
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

    int ans = canJump(v);
    cout <<ans << endl; 
    return 0;
}