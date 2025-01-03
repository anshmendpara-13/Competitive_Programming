#include <bits/stdc++.h>

using namespace std;

const int N = 1e7+7;
int arr[N];

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        arr[a[i]]++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        // int cnt = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (a[i] == x)
        //     {
        //         cnt++;
        //     }
        // }
        // cout << cnt << endl;

        cout << arr[x] << endl; 
    }

    // cout <<  <<endl;
    return 0;
}