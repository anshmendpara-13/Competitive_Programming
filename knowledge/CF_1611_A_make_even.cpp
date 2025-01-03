#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        int ans = -1;
        if ((s[n - 1] - '0') % 2 == 0)
        {
            ans = 0;
        }
        else if ((s[0] - '0') % 2 == 0)
        {
            ans = 1;
        }
        else
        {
            bool checker = false;
            for (int i = 0; i < n; i++)
            {
                if ((s[i] - '0') % 2 == 0)
                {
                    checker = true;
                    break;
                }
            }
            if (checker)
            {
                ans = 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}