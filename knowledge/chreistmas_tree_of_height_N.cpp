#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int level;
        cin >> level;
        int a[level][level];
        a[0][0] = 1;

        for (int i = 1; i <= level; i++)
        {
            a[i][0] = 1;
            a[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }

        for (int i = 0; i < level; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    // cout <<  <<endl;
    return 0;
}