#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string customSortString(string order, string s)
{
    string ans = "";

    for (int i = 0; i < order.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (order[i] == s[j])
            {
                ans += order[i];
            }
        }
    }

    for (int i = 0; i < ans.length(); i++)
    {
        char ch = ans[i];
        s.erase(remove(s.begin(), s.end(), ch), s.end());
    }

    return (s+ans);
}

int main()
{
    string order, s;
    cin >> order;
    cin >> s;

    cout << customSortString(order, s) << endl;
    return 0;
}