#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll M = 1e9 + 7;
const ll N = 1e6 + 10;
ll fact[N];

ll binExp(ll a, ll b, ll m)
{
    ll result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}

int main()
{
    // alphabet --K ; N size password ; K>N
    // KCN
    // N!*KCN

    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % M;
    }

    ll q;
    cin >> q;
    while (q--) // q*log(n) + constant
    {
        ll n, k;
        cin >> n >> k;
        ll den = (fact[n - k] * 1LL * fact[k]) % M;
        ll ans = (fact[n] % M) * binExp(den, M - 2, M) % M;
        cout << (fact[n] * ans) % M << endl;
        // cout << fact[n] / ((fact[n - k] * fact[k]) % M) << endl;
    }

    return 0;
}