#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 7;
long long a[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= m;
    }

    sort(a, a + n);
    int q;
    cin >> q;
    while (q--)
    {
        long long x;
        cin >> x;
        x %= m;

        long long *ptr = upper_bound(a, a + n, m - x - 1);
        // cout << m - x - 1 << endl;
        // cout << *ptr << endl;
        if (ptr != a)
        {
            ptr--;
        }
        // cout << *ptr << endl;
        cout << max((a[n - 1] + x) % m, (*ptr + x) % m) << endl;
    }

    return 0;
}