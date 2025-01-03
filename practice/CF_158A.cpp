#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    int temp;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cmp = arr[k - 1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= cmp && arr[i]!=0)
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}