#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;

    vector<int> masks(n, 0);

    for (int i = 0; i < n; i++)
    {
        int days;
        cin >> days;

        int mask = 0;
        for (int j = 0; j < days; j++)
        {
            int day;
            cin >> day;
            mask |= (1 << day);
        }
        masks[i] = mask;
    }

    int maxCommonDays = INT_MIN;
    vector<vector<int>> maxPairs;
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int intersection = (masks[i] & masks[j]);
            int common_days = __builtin_popcount(intersection);

            if (common_days > maxCommonDays)
            {
                maxCommonDays = common_days;
                maxPairs.clear();
                maxPairs.push_back({i, j});
                s.clear();
                s.insert(i);
                s.insert(j);
            }
            else if (common_days == maxCommonDays)
            {
                maxPairs.push_back({i, j});
                s.insert(i);
                s.insert(j);
            }
        }
    }

    cout << "Maximum common days: " << maxCommonDays << endl;
    cout << "Pairs with maximum common days: " << endl;
    for (auto pair : maxPairs)
    {
        cout << pair[0] << " " << pair[1] << endl;
    }

    cout << "set values" << endl;
    for (auto val : s)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
