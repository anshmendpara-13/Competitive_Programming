#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] != nums[i + 1] && cnt == 0)
            return nums[i];
        if (nums[i] == nums[i + 1])
            cnt++;
        else
            cnt = 0;
    }

    return nums[nums.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << singleNumber(a) << endl;
    return 0;
}