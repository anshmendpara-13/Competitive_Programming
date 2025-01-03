#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    int cnt = 1;
    while (i <= n)
    {
        int j = 1;
        cnt = i;
        while (j <= i)
        {
            cout << cnt
                 << " ";
            j += 1;
            cnt--;
        }
        cout << endl;
        // cnt++;
        i += 1;
    }

    // cout <<  <<endl;
    return 0;
}