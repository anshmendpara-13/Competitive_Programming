#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.empty())
        return 0;

    sort(points.begin(), points.end());
    int ans = 1;

    int end_point = points[0][1];

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] <= end_point)
        {
            end_point = min(end_point, points[i][1]);
        }
        else
        {
            ans++;
            end_point = points[i][1];
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    int ans = findMinArrowShots(a);
    cout << ans << endl;

    return 0;
}
