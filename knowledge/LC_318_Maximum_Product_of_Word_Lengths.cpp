#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int maxProduct(vector<string> &words)
{
    int n = words.size();
    vector<int> bitmask(n);

    for (int i = 0; i < n; ++i)
    {
        for (char ch : words[i])
        {
            bitmask[i] |= (1 << (ch - 'a'));
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((bitmask[i] & bitmask[j]) == 0)
            {
                ans = std::max(ans, static_cast<int>(words[i].length() * words[j].length()));
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    cout << maxProduct(s) << endl;
    return 0;
}