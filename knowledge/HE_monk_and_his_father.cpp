#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        cout << __builtin_popcountll(x) << endl;
    }

    return 0;
}