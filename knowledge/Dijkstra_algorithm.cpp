// LC_743_Network_Delay_Time ******************

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int N = 1e5 + 7;
const int INF = 1e9 + 7;

vector<pair<int, int>> g[N];

int dijkstra(int source, int n, vector<pair<int, int>> g[N])
{
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);

    set<pair<int, int>> st; // weight and node
    st.insert({0, source});
    dist[source] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin(); // first element of set
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if (vis[v])
            continue;
        vis[v] = 1;

        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;

            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<pair<int, int>> g[N];
    for (auto vec : times)
    {
        g[vec[0]].push_back({vec[1], vec[2]});
    }
    return dijkstra(k, n, g);
}

int main()
{

    int s, ss;
    cin >> s >> ss;
    vector<vector<int>> times(s, vector<int>(ss));
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < ss; j++)
        {
            cin >> times[i][j];
        }
    }
    int n, k;
    cin >> n >> k;
    cout << networkDelayTime(times, n, k) << endl;

    return 0;
}