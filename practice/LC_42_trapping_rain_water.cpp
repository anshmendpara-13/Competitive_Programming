#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    vector<int> l(n); // l[i] := max(arr[0..i])
    vector<int> r(n); // r[i] := max(arr[i..n))

    for (int i = 0; i < n; ++i)
    {
        l[i] = (i == 0) ? arr[i] : max(arr[i], l[i - 1]);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        r[i] = (i == n - 1) ? arr[i] : max(arr[i], r[i + 1]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << l[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << r[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     ans += min(l[i], r[i]) - arr[i];
    // }
    // cout << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << min(l[i], r[i]) << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << min(l[i], r[i]) - arr[i]<< " ";
    // }

    for (int i = 0; i < n; ++i)
    {
        ans += min(l[i], r[i]) - arr[i];
    }

    cout << ans << endl;
    return 0;
}
// 2 0 2 0 0 2 0 0 0
// 0 3 4 0 3