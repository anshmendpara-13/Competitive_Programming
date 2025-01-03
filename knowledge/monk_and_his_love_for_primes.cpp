#include <bits/stdc++.h>

using namespace std;

char upper(char c)
{
    return 'A' + (c - 'a');
}
char lower(char c)
{
    return 'a' + (c - 'A');
}

int main()
{
    int n;
    string s;
    cin >> s;

    int total = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = upper(s[i]);
            // cout << s[i] << endl;
            total = total + (s[i]);
        }
        else
        {
            s[i] = lower(s[i]);
            // cout << s[i] << endl;
            total = total - (s[i]);
        }
    }
    if (total < 0)
    {
        total = total * -1;
    }

    int isprime = 1;

    for (int i = 2; i < total; i++)
    {
        if (total % i == 0)
        {
            isprime = 0;
            break;
        }
    }

    cout << isprime << endl;

    return 0;
}