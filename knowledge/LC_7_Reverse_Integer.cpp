#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int reverse(int x)
{
    long long digit_ct = 0;
    bool is_neg = false;
    long long z = x;
    if (x < 0)
    {
        is_neg = true;
        x = z + (-2 * z);
    }

    string s = to_string(x);

    for (long long i = 0; i < s.size() / 2; i++)
    {
        swap(s[i], s[s.size() - 1 - i]);
    }

    long long ans = 0;
    long long left = 1;
    for (long long i = s.size() - 1; i >= 0; i--)
    {
        long long x = (s[i] - '0') * left;
        left *= 10;
        ans += x;
    }

    if (is_neg)
    {
        ans = (-1) * ans;
    }

    if (ans > INT_MAX || ans < INT_MIN)
    {
        return 0;
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    cout << reverse(n) << endl;
    return 0;
}