#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int func(string &s) // O(N^2)
{
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int v[3] = {0};

        for (int j = i; j < s.length(); j++)
        {
            v[s[j] - 'a'] = 1;
            if (v[0] + v[1] + v[2] == 3)
                cnt = cnt + 1;
        }
    }
    return cnt;
}

int func1(string &s) // O(N)
{
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int v[3] = {0};

        for (int j = i; j < s.length(); j++)
        {
            v[s[j] - 'a'] = 1;
            if (v[0] + v[1] + v[2] == 3)
            {
                cnt = cnt + (s.length() - j);
                break;
            }
        }
    }
    return cnt;
}   

int func2(string &s)
{
    int cnt = 0;
    int lastseen[3] = {-1, -1, -1};

    for (int i = 0; i < s.length(); i++)
    {
        lastseen[s[i] - 'a'] = i;
        if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1)
            cnt += 1 + min(min(lastseen[0], lastseen[1]), lastseen[2]);
    }
    return cnt;
}

int main()
{

    string s;
    cin >> s;

    // cout << func(s) << endl;
    // cout << func1(s) << endl;
    cout << func2(s) << endl;

    return 0;
}