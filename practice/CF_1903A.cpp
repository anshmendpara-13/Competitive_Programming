#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        vector<ll> v1(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            v1[i] = v[i];
        }
        sort(v.begin(), v.end());

        ll issame = true;
        for (size_t i = 0; i < v.size(); ++i)
        {
            if (v[i] != v1[i])
            {
                issame = false;
            }
        }

        if (k <= 1 && (!issame))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}