#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> summaryRanges(vector<long long> &nums)
{
    vector<string> str;
    long long n = nums.size();
    for (long long i = 0; i < n; i++)
    {
        long long startNum = nums[i];
        while (i + 1 < n && nums[i + 1] == nums[i] + 1)
        {
            i++;
        }
        long long endNum = nums[i];
        if (startNum != endNum)
        {
            str.push_back(to_string(startNum) + "->" + to_string(endNum));
        }
        else
        {
            str.push_back(to_string(startNum));
        }
    }
    return str;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<string> ans = summaryRanges(v);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}