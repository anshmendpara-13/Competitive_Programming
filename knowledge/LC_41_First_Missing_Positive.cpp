#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int firstMissingPositive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 1;
    sort(nums.begin(), nums.end());
    
    int k;
    if (nums.size() <= 50000)
    {
        k = 1;
        for (int i = 0; i < 50001; i++)
        {
            bool flag = count(nums.begin(), nums.end(), k);
            if (!flag)
                return k;
            else
                k++;
            continue;
        }
    }
    else
    {
        k = 50001;
        for (int i = 50001; i < nums.size() + 1; i++)
        {
            bool flag = count(nums.begin(), nums.end(), k);
            if (!flag)
                return k;
            else
                k++;
            continue;
        }
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
    cout << firstMissingPositive(v) << endl;
    // cout <<  <<endl;
    return 0;
}