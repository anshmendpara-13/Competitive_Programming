#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int subarraySum(vector<int> &nums, int k)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i ; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                ans++;
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

    int k;
    cin >> k;
    cout << subarraySum(v, k) << endl;

    return 0;
}