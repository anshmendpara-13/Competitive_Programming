#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // int start = 1;
    int start = n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            // cout << char(i + 64)
            // cout << char(i + 'A' -1)
            // cout << char(j + 'A' -1)
            // cout << char(i + j + 'A' - 2)
            // cout << char((i * j) + 'A' - 1)
            cout << char(start + 'A' - 1)
                 << " ";
            j += 1;
            start++;
        }
        start -= i + 1;
        cout << endl;
        i += 1;
    }

    // cout <<  <<endl;
    return 0;
}