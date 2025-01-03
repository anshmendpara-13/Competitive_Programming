#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int missingNumber(vector<int> &nums)
{
    if (nums.empty())
        return 1;

    sort(nums.begin(), nums.end());

    unordered_set<int> seen(nums.begin(), nums.end());

    int smallestMissing = 0;
    while (seen.count(smallestMissing) > 0)
    {
        smallestMissing++;
    }

    return smallestMissing;
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

    cout << missingNumber(a) << endl;
    return 0;
}