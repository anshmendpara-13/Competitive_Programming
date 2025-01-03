#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

static bool cmp(string a, string b)
{
    if (a.size() < b.size())
        return true;
    if (a.size() == b.size() && a < b)
        return true;
    return false;
}
vector<string> shortestSubstrings(vector<string> &arr)
{
    int n = arr.size();
    vector<string> ans(n);
    vector<vector<string>> substring(n);
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        int k = arr[i].size();
        for (int j = 0; j < k; j++)
        {
            string sub = "";
            for (int l = j; l < k; l++)
            {
                sub += arr[i][l];
                bool found = false;
                for (const auto &str : substring[i])
                {
                    if (str == sub)
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                    continue;
                m[sub]++;
                substring[i].push_back(sub);
            }
        }
        sort(substring[i].begin(), substring[i].end(), cmp);
    }
    for (int i = 0; i < n; i++)
    {
        for (auto it : substring[i])
        {
            if (m[it] == 1)
            {
                ans[i] = it;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    // n size array of element bitmask is 2^n-1, so we can use it to represent the number from binary representation
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<string> ans = shortestSubstrings(nums);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}