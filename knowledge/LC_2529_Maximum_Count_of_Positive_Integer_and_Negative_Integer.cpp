#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int maximumCount(vector<int> &nums)
{
    int neg_max = 0;
    int pos_max = 0;
    for (auto val : nums)
    {
        if (val < 0)
        {
            neg_max++;
        }
        else if (val > 0)
        {
            pos_max++;
        }
    }
    return max(neg_max, pos_max);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maximumCount(nums) << endl;

    return 0;
}