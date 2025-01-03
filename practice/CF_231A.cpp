#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n][3];

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            temp += arr[i][j];
        }
        if (temp >= 2)
        {
            total += 1;
        }
    }

    cout << total << endl;

    return 0;
}