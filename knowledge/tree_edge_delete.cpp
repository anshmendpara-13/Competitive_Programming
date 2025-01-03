#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int M = 1e9 + 7;
vector<int> g[N];
int sub_tree_sum[N];
int val[N];

void dfs(int vertex, int parent)
{
    sub_tree_sum[vertex] = val[vertex]; // Initialize sub_tree_sum with the value of the current node

    for (auto child : g[vertex])
    {
        if (child == parent)
            continue;

        dfs(child, vertex);
        sub_tree_sum[vertex] += sub_tree_sum[child]; // Add the sum of child subtrees to the current node
    }
}

int main()
{
    int n, m;
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, -1);

    long long ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int part1 = sub_tree_sum[i];
        int part2 = sub_tree_sum[1] - part1;
        ans = max(ans, 1LL * part1 * part2); // Avoid overflow by using long long
    }

    cout << ans << endl;

    return 0;
}
