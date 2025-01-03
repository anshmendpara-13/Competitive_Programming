#include <bits/stdc++.h>

using namespace std;

bool isvowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); }

vector<string> subsets(string s) // subset generate using bit masking tech...
{
    int sz = 1 << s.size();
    vector<string> ans;
    for (int i = 0; i < sz; i++)
    {
        string subset;
        for (int j = 0; j < s.size(); j++)
        {
            if (i & (1 << j))
            {
                subset.push_back(s[j]);
            }
        }
        if (subset.size()) //  checking for subset not empty
        {

            ans.push_back(subset);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string str[n];
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }

        unordered_map<string, int> hsh;
        for (int i = 0; i < n; i++)
        {
            set<char> distict_vw;
            for (auto ch : str[i])
            {
                if (isvowel(ch))
                {
                    distict_vw.insert(ch);
                }
            }

            string vowel_str;
            for (auto ch : distict_vw)
            {
                vowel_str.push_back(ch);
            }

            vector<string> all_subsets = subsets(vowel_str);

            for (auto vowel_subset : all_subsets)
            {
                hsh[vowel_subset]++;
            }
        }
        // for (auto i : hsh)
        // {
        //     cout << i.first << " " << i.second << endl;
        // }
        // cout << endl;

        int ans = 0;

        for (auto &pr : hsh)
        {
            if (pr.second < 3)
            {
                continue;
            }
            long long ct = pr.second;
            long long ways = (ct * (ct - 1) * (ct - 2)) / 6;
            if (pr.first.size() % 2 == 0)
            {
                ans -= ways;
            }
            else
            {
                ans += ways;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
