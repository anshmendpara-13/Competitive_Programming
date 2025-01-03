#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int removeElement(vector<int> &nums, int val)
{
    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    return nums.size();
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

    int k;
    cin >> k;
    int ans = removeElement(a, k);
    cout << ans << endl;

    return 0;
}