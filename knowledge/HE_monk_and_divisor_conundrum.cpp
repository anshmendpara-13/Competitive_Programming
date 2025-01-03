#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll N = 2e5 + 7;

ll mulitples_ct[N];
ll hsh[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            mulitples_ct[i] += hsh[j];
        }
    }

    for (int i = 1; i < N; i++)
    {
        cout << i << " " << mulitples_ct[i] << endl;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int p, q;
        cin >> p >> q;
        long long lcm = (p * 1LL * q) / __gcd(p, q);
        long long ans = mulitples_ct[p] + mulitples_ct[q];
        if (lcm < N)
        {
            ans -= mulitples_ct[lcm];
        }
        // cout << ans << endl;
    }

    return 0;
}