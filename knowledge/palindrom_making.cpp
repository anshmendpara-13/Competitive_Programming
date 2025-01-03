#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int hsh[N][26];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                hsh[i][j] = 0;
            }
        }

        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        for (int i = 0; i < n; i++)
        {
            hsh[i+1][s[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                hsh[j][i] += hsh[j - 1][i];
            }
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            // int hsh[26];
            // for (int i = 0; i < 26; i++)
            // {
            //     hsh[i] = 0;
            // }
            // l--, r--;
            // for (int i = l; i <= r; i++)
            // {
            //     hsh[s[i] - 'a']++;
            // }
            int oddCt = 0;
            // for (int i = 0; i < 26; i++)
            // {
            //     if (hsh[i] % 2 != 0)
            //     {
            //         oddCt++;
            //     }
            // }

            for (int i = 0; i < 26; i++)
            {
                int charCt = hsh[r][i] - hsh[l - 1][i];
                if (charCt % 2 != 0)
                {
                    oddCt++;
                }
            }

            if (oddCt > 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }

    // cout <<  <<endl;
    return 0;
}