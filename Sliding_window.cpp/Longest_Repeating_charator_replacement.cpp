#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int func(string &s, int &k) // O(N^2)
{
    int maxfreq = 0;
    int result = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int hsh[26] = {0};
        maxfreq = 0; // Reset maxfreq for each starting point

        for (int j = i; j < s.length(); j++)
        {
            hsh[s[j] - 'A']++;
            maxfreq = max(maxfreq, hsh[s[j] - 'A']);
            int change = (j - i + 1) - maxfreq;
            if (change <= k)
                result = max(result, j - i + 1); // Update result if the current window is valid
        }
    }
    return result;
}

int func1(string &s, int &k) // O((N+N)*26)
{
    int maxlen = 0, maxfreq = 0, l = 0, r = 0;
    int hsh[26] = {0}; // S(26)

    while (r < s.length())
    {
        hsh[s[r] - 'A']++;
        maxfreq = max(maxfreq, hsh[s[r] - 'A']);

        while ((r - l + 1) - maxfreq > k)
        {
            hsh[s[l] - 'A']--;
            maxfreq = 0;
            for (int i = 0; i < 26; i++)
            {
                maxfreq = max(maxfreq, hsh[i]);
            }
            l++;
        }
        if ((r - l + 1) - maxfreq <= k)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int func2(string &s, int &k) // O(N)
{
    int maxlen = 0, maxfreq = 0, l = 0, r = 0;
    int hsh[26] = {0}; // S(26)

    while (r < s.length())
    {
        hsh[s[r] - 'A']++;
        maxfreq = max(maxfreq, hsh[s[r] - 'A']);

        if ((r - l + 1) - maxfreq > k)
        {
            hsh[s[l] - 'A']--;
            maxfreq = 0;
            l++;
        }
        if ((r - l + 1) - maxfreq <= k)
            maxlen = max(maxlen, r - l + 1);
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

    cout << func2(s, k) << endl;
    return 0;
}