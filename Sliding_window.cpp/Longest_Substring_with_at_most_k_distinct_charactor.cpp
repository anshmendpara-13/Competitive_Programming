#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int func(string &s, int k)
{
    int maxlen = 0;
    unordered_map<char, int> mp; // S(log(256)) -> we store the char

    for (int i = 0; i < s.length(); i++) // O(n^2)
    {
        mp.clear();
        for (int j = 0; j < s.length(); j++)
        {
            mp[s[j]]++;
            if (mp.size() <= k)
            {
                maxlen = max(maxlen, j - i + 1);
            }
            else
                break;
        }
    }
    return maxlen;
}

int func1(string &s, int k)
{
    int maxlen = 0;
    int l = 0, r = 0;

    unordered_map<char, int> mp; // O(2*N)

    while (r < s.length())
    {
        mp[s[r]]++;

        while (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }
        if (mp.size() <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

int func2(string &s, int k)
{
    int maxlen = 0;
    int l = 0, r = 0;

    unordered_map<char, int> mp; // O(N)

    while (r < s.length())
    {
        mp[s[r]]++;

        if (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }

        if (mp.size() <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

int main()
{

    string s;
    cin >> s;
    int k;
    cin >> k;

    // cout << func(s, k) << endl;
    // cout << func1(s, k) << endl;
    cout << func2(s, k) << endl;
    return 0;
}