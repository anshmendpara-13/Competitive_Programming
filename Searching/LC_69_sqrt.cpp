#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ct = 0;

ll squareroot(ll n)
{
    ll s = 0;
    ll e = n;
    ll mid = s + (e - s) / 2;
    ll ans = -1;
    while (s <= e)
    {
        ll sq = mid * mid;
        if (sq == n)
        {
            return mid;
        }
        else if (sq < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
            ct++;
        }
        mid = s + ((e - s) / 2);
    }
    return ans;
}

int main()
{

    ll n;
    cin >> n;

    // search space are linear so binary search apply

    cout << squareroot(n) << endl;
    // cout << ct << endl;
    return 0;
}