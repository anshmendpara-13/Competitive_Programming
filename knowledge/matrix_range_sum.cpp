#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10;
int arr[N][N];

int main()
{
    int n;
    cin >> n;

    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[1][0] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        long long int sum = 0;

        // for (int i = a; i <= c; i++)
        // {
        //     for (int j = b; j <= d; j++)
        //     {
        //         sum += arr[i][j];
        //     }
        // }
        // cout << sum << endl;

        cout << arr[c][d] - arr[a - 1][d] - arr[c][b - 1] + arr[a - 1][b - 1] << endl;
    }

    // cout <<  <<endl;
    return 0;
}