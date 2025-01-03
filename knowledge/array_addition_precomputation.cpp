#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;
long long int arr[N];

int main()
{
    int n, q;
    cin >> n >> q;
    arr[0]=0;

    while (q--)
    {
        int start, end, num;
        cin >> start >> end >> num;

        // for (int i = start; i <= end; i++)
        // {
        //     arr[i] += num;
        // }

        arr[start] += num;
        arr[end + 1] -= num;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i-1];
    }

    cout << *max_element(arr, arr + n) << endl;

    // cout <<  <<endl;
    return 0;
}