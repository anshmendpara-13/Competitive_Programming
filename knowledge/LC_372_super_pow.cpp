#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int binExpIter(int a, int b, int m)
{
    a %= m;
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}

int superPow(int a, vector<int> &v)
{
    int ans = 0;
    for (int val : v)
    {
        ans = (ans * 10 + val) % 1140;
    }
    if (ans == 0)
    {
        ans = 1140;
    }
    return binExpIter(a, ans, 1337);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int a;
    cin >> a;

    cout << superPow(a, v) << endl;

    return 0;
}