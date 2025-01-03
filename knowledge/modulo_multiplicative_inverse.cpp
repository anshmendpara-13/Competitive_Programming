#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    // (A*B) mod M = 1 ; 1<=B<=M-1 ; A and M are co-prime ; gcd(A,M)=1 so you can find  B by Euler's totient function
    // ll a, b, m;
    // cin >> a >> m;
    // if (__gcd(a, m) != 1)
    // {
    //     cout << "NOT found" << endl;
    //     return 0;
    // }
    // for (ll i = 1; i < m; i++) // O(n)
    // {
    //     if (((a * i) % m) == 1)
    //     {
    //         cout << i << endl;
    //     }
    // }

    // A^(M-1) = 1 mod M  --> fermet's little theorem ;  M is prime && A is not multiple of M
    // A^(M-2) = (A^-1) mod M =>  A^(M-2) mod M = (A^-1) --> which we need

    // ll ans = binExp(a, m - 2, m);
    // cout << ans << endl;

    // Q1 -> there are N children and K toffees. K<N count the number of ways to distribute toffee among N students such that each student get 1 toffee only for Q quieries
    // N < 10^6 ; K < N < 10^6 Q < 10^5-> nCk ; M = 10^9+7
    // n! / (n-r)!*(r)! % M

    // pre-compute the factorial **********
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % M;
    }

    // for (ll i = 0; i < 6; i++) // cheking factorial list
    // {
    //     cout << fact[i] << endl;
    // }

    ll q;
    cin >> q;
    while (q--)
    {
        ll n, k;
        cin >> n >> k;
        ll den = (fact[n - k] * 1LL * fact[k]) % M;
        ll ans = (fact[n] % M) * binExp(den, M - 2, M) % M;
        cout << ans << endl;
        // cout << fact[n] / ((fact[n - k] * fact[k]) % M) << endl;
    }
    return 0;
}