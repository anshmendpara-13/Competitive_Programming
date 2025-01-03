#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int a[N];

int main()
{
    int n;
    cin >> n;
    long long int pre = 0;
    long long int arr[N];
    arr[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        arr[i] = arr[i - 1] + a[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        // long long sum = 0;
        // for (int i = l; i <= r; i++)
        // {
        //     sum += a[i];
        // }
        // cout << sum << endl;
        // cout << arr[l+1]-arr[r] << endl;
        cout << arr[r] - arr[l - 1] << endl;
    }

    // cout <<  <<endl;
    return 0;
}