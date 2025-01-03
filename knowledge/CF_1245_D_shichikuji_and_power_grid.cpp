#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long N = 2e3 + 7;
long long parent[N];
long long sizee[N];

void make(long long v)
{
    sizee[v] = 1;
    parent[v] = v;
}

long long find(long long v)
{
    if (v == parent[v])
        return v;
    // below line is path compression
    return parent[v] = find(parent[v]);
}

void Union(long long a, long long b)
{
    a = find(a);
    b = find(b);
    // size(current tree size) and rank(depth): for merge the tree
    // below line is union by rank : take the smaller one
    if (a != b)
    {
        if (sizee[a] > sizee[b])
        {
            parent[a] = b;
            sizee[b] += sizee[a];
        }
        else
        {
            parent[b] = a;
            sizee[a] += sizee[b];
        }
    }
}

int main()
{
    /*
    minimum spanning tree
    */

    long long n;
    cin >> n;

    vector<pair<long long, long long>> cities(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<long long> c(n + 1), k(n + 1);

    for (long long i = 1; i <= n; i++) // power plant cost
    {
        cin >> c[i];
    }
    for (long long i = 1; i <= n; i++) // connect line cost
    {
        cin >> k[i];
    }

    vector<pair<long long, pair<long long, long long>>> edges;
    for (long long i = 1; i <= n; i++)
    {
        edges.push_back({c[i], {0, i}});
    }
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i + 1; j <= n; j++)
        {
            long long dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            long long cost = dist * 1LL * (k[i] + k[j]);
            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    for (long long i = 1; i <= n; i++)
        make(i);

    long long total_cost = 0;
    vector<long long> power_station;
    vector<pair<long long, long long>> connections;

    for (auto edge : edges)
    {
        long long wt = edge.first;
        long long u = edge.second.first;
        long long v = edge.second.second;

        if (find(u) == find(v))
            continue;

        Union(u, v);
        total_cost += wt;

        if (u == 0 || v == 0)
        {
            power_station.push_back(max(u, v));
        }
        else
        {
            connections.push_back({u, v});
        }
    }
    cout << total_cost << endl;
    cout << power_station.size() << endl;
    sort(power_station.begin(), power_station.end());
    for (auto powerstate : power_station)
    {
        cout << powerstate << " ";
    }
    cout << endl;
    cout << connections.size() << endl;
    for (auto connection : connections)
    {
        cout << connection.first << " " << connection.second << endl;
    }

    return 0;
}