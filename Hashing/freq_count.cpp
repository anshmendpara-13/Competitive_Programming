#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // pre calculations
    int hsh[100001];
    memset(hsh, 0, sizeof(hsh));

    for (int i = 0; i < n; i++)
    {
        hsh[a[i]]++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;
        cout << hsh[number] << endl;
    }

    return 0;
}