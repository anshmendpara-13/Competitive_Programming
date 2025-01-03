#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int pivotIndex(vector<int> &nums)
{
    int right_sum = accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        right_sum -= nums[i];
        if (right_sum == left_sum)
        {
            return i;
        }
        left_sum += nums[i];
    }
    return -1;
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

    cout << pivotIndex(v) << endl;

    return 0;
}