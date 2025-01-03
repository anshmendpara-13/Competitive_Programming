#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    // your code goes here
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, n;
        ll sum = 0;
        cin >> n >> x;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            ll y;
            cin >> y;
            a[i] = y;
            sum += y;
        }
        sort(a, a + n);
        ll ex = 0;
        ll cnt = 0;

        for (ll i = n - 1; i >= 0; i--)
        {
            if (a[i] >= x)
            {
                ex += (a[i] - x);
                cnt++;
            }
            else if ((x - a[i]) <= ex)
            {
                ll tp = x - a[i];
                ex -= tp;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}