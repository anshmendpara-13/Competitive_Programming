#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
{
    priority_queue<pair<long long, int>> pq;
    map<int, long long> mp;
    vector<long long> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] += freq[i];
        pq.push({mp[nums[i]], nums[i]}); // store first freq and then value
        while (true)
        {
            pair<long long, int> p = pq.top();
            if (p.first == mp[p.second])
            {
                ans.push_back(p.first);
                break;
            }
            else
            {
                pq.pop();
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> freq(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }

    vector<long long> ans = mostFrequentIDs(nums, freq);
    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}