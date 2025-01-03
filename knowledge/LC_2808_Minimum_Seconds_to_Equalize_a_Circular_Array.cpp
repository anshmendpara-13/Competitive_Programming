#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int minimumSeconds(vector<int> &nums)
{
    // hash mapping concept unsold
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

    int ans = minimumSeconds(a);
    cout << ans << endl;

    return 0;
}