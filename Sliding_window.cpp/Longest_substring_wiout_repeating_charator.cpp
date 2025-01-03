// SV - L3
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int func(string &s)
{
    int hsh[256];
    memset(hsh, -1, sizeof(hsh));

    int l = 0, r = 0, maxlen = 0;

    while (r < s.size())
    {
        if (hsh[s[r]] != -1)
        {
            if (hsh[s[r]] >= l)
                l = hsh[s[r]] + 1;
        }
        int len = r - l + 1;
        maxlen = max(maxlen, len);
        hsh[s[r]] = r;
        r++;
    }

    return maxlen;
}
int main()
{

    string s;
    cin >> s;
    cout << func(s) << endl;
    return 0;
}