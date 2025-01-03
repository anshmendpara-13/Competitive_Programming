#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    if (n == 0)
        return {newInterval};

    vector<vector<int>> ans;
    vector<int> vv = {newInterval[0], newInterval[1]};
    bool inserted = false;

    for (auto &sv : intervals)
    {
        if (sv[1] < vv[0]) // current interval ends before new interval starts
        {
            ans.push_back(sv);
        }
        else if (sv[0] > vv[1]) // current interval starts after new interval ends
        {
            if (!inserted)
            {
                ans.push_back(vv);
                inserted = true;
            }
            ans.push_back(sv);
        }
        else // overlap between current interval and new interval
        {
            vv[0] = min(vv[0], sv[0]);
            vv[1] = max(vv[1], sv[1]);
        }
    }

    if (!inserted)
    {
        ans.push_back(vv);
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<int> newinter(2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int k = 0; k < 2; k++)
    {
        cin >> newinter[k];
    }

    vector<vector<int>> ans = insert(v, newinter);

    for (auto sa : ans)
    {
        for (auto val : sa)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
