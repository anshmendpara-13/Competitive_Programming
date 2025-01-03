#include <bits/stdc++.h>

using namespace std;

string func(string &s, string &t)
{
    int minlen = INT_MAX;
    int startindex = -1;

    for (int i = 0; i < s.length(); i++) // O(N^2)
    {
        int hsh[256] = {0};
        int cnt = 0;

        for (int j = 0; j < t.length(); j++)
        {
            hsh[t[j]]++;
        }

        for (int j = i; j < s.length(); j++)
        {
            if (hsh[s[j]] > 0)
            {
                cnt++;
                hsh[s[j]]--;
            }

            if (cnt == t.length())
            {
                if (j - i + 1 < minlen)
                {
                    minlen = j - i + 1;
                    startindex = i;
                    break;
                }
            }
        }
    }

    if (startindex == -1)
    {
        return "";
    }

    return s.substr(startindex, minlen);
}

string func1(string &s, string &t)
{
    int minlen = INT_MAX;
    int startindex = -1;
    int l = 0, r = 0, cnt = 0;
    int hsh[256] = {0};

    for (int j = 0; j < t.length(); j++)
    {
        hsh[t[j]]++;
    }

    while (r < s.length())
    {
        if (hsh[s[r]] > 0)
        {
            cnt++;
        }
        hsh[s[r]]--;
        while (cnt == t.length())
        {
            if (r - l + 1 < minlen)
            {
                minlen = r - l + 1;
                startindex = l;
            }
            hsh[s[l]]++;
            if (hsh[s[l]] > 0)
            {
                cnt--;
            }
            l++;
        }
        r++;
    }
    return startindex == -1 ? "" : s.substr(startindex, minlen);
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;

    cout << func1(s, t) << endl;
    return 0;
}
