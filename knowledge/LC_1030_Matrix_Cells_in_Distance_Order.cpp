#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
{
    vector<vector<int>> temp;
    vector<pair<int, pair<int, int>>> v;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int x = abs(i - rCenter);
            int y = abs(j - cCenter);
            v.push_back({abs(i - rCenter) + abs(j - cCenter), {i, j}});
        }
    }

    sort(v.begin(), v.end());

    for (auto &i : v)
    {
        temp.push_back({i.second.first, i.second.second});
    }
    return temp;
}

int main()
{
    int r, c, rc, cc;
    cin >> r >> c >> rc >> cc;
    vector<vector<int>> v;
    v = allCellsDistOrder(r, c, rc, cc);

    for (auto tv : v)
    {
        for (auto val : tv)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}