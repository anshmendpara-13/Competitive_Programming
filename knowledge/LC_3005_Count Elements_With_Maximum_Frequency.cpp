#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int maxFrequencyElements(vector<int> &nums)
{
    map<int, int> frequencyMap;

    for (auto i : nums)
    {
        frequencyMap[i]++;
    }

    int total = 0;
    int temp = 0;
    for (auto i : frequencyMap)
    {
        int x = i.second;
        temp = max(temp, x);
    }

    for (auto i : frequencyMap)
    {
        if (i.second == temp)
            total++;
    }

    return temp*total;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << maxFrequencyElements(nums) << endl;

    return 0;
}