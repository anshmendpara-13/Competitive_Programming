#include <bits/stdc++.h>
using namespace std;

vector<int> GeekAndString(vector<string> &words,
                          vector<string> &Queries)
{
    vector<int> ans;
    for (string x : Queries)
    {
        int count = 0;
        for (string word : words)
        {
            if (word.size() < x.size())
                continue;

            if (word.substr(0, x.size()) == x)
                count++;
        }
        ans.push_back(count);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    int q;
    cin >> q;
    vector<string> queries(q);

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }

    vector<int> ans = GeekAndString(words, queries);
    for (int x : ans)
        cout << x << " ";

    return 0;
}
