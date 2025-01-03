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

double moreprecision(int n, int precision, int temp)
{
    double factor = 1;
    double answer = temp;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = answer; j * j < n; j+= factor)
        {
            answer = j;
        }
    }
    return answer;
}

int main()
{

    ll n, p;
    cin >> n >> p;

    // search space are linear so binary search apply
    // cout << ct << endl;

    int temp = squareroot(n);

    cout << moreprecision(n, p, temp) << endl;

    return 0;
}