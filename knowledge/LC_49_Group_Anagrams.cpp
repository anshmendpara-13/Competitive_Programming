#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;

    for (auto x : strs)
    {
        string word = x;
        sort(word.begin(), word.end());
        mp[word].push_back(x);
    }

    vector<vector<string>> ans;
    for (auto x : mp)
    {
        ans.push_back(x.second);
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

    vector<vector<string>> ans = groupAnagrams(s);


    for (auto fa : ans)
    {
        for (auto val : fa)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}