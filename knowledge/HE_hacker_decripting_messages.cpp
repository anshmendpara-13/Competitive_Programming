#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll N = 2e5 + 10;
ll a[N];
ll hp[N];
ll canremove[N]; // canremove[i] ->> if i can be removed - 1,0
ll hsh[N];

vector<ll> distincePF(ll x) // distinct prime factor
{
    vector<ll> ans;
    while (x > 1)
    {
        ll pf = hp[x];
        while ((x % pf) == 0)
        {
            x /= pf;
        }
        ans.push_back(pf);
    }
    return ans; // Added return statement
}

int main()
{
    for (ll i = 2; i < N; i++) // max divisor store in each element
    {
        if (hp[i] == 0)
        {
            for (ll j = i; j < N; j += i)
            {
                hp[j] = i;
            }
        }
    }

    // for (int i = 2; i < N; i++) // print all max divisor of each element
    // {
    //     cout << i << " " << hp[i] << endl;
    // }

    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        hsh[x] = 1;
    }

    // for (int i = 0; i < 23; i++)
    // {
    //     cout << i << " " << hsh[i] << endl;
    // }

    for (ll i = 2; i < N; i++)
    {
        if (hsh[i])
        {
            for (ll j = i; j < N; j *= i)
            {
                canremove[j] = 1;
            }
        }
    }

    while (q--)
    {
        ll x;
        cin >> x;
        vector<ll> pf = distincePF(x);

        // for (auto val : pf)
        // {
        //     cout << val << " ";
        // }
        // cout << endl;

        bool isPossible = false;
        for (ll i = 0; i < pf.size(); i++)
        {
            for (ll j = i; j < pf.size(); j++)
            {
                ll product = pf[i] * pf[j]; // Changed this line
                if ((i == j) && (x % product != 0))
                {
                    continue;
                }
                ll toremove = x / product;
                if (canremove[toremove] == 1)
                {
                    isPossible = true;
                    break;
                }
            }
            if (isPossible)
            {
                break;
            }
        }
        if (isPossible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
