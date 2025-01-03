#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    set<pair<int, int>> point_st;

    // in unorder_set, we not use pair in that case we only use int, double, string, etc...

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
        point_st.insert(points[i]);
    }

    int ar_min = INT_MAX, ar_max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto p1 = points[i];
            auto p2 = points[j];
            if (p1.first == p2.first)
                continue;
            if (p1.second == p2.second)
                continue;
            if (p1.first > p2.first)
                swap(p1, p2);
            int x1 = p1.first, y1 = p2.second;
            int x2 = p2.first, y2 = p1.second;
            if (point_st.count({x1, y1}) && point_st.count({x2, y2})) // count to find in unorderset log(n)
            {
                int ar = abs(p1.first - p2.first) * abs(p1.second - p2.second);
                ar_min = min(ar_min, ar);
                ar_max = max(ar_max, ar);
            }
        }
    } // all over n^2*log(n)

    if (ar_min == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ar_max - ar_min << endl;
    }
    return 0;
}
