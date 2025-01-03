#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int romanToInt(string s)
{
    map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i > 0 && m[s[i]] > m[s[i - 1]])
        {
            res += m[s[i]] - 2 * m[s[i - 1]];
        }
        else
        {
            res += m[s[i]];
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
    return 0;
}