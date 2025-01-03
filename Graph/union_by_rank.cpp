#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
class disjointset
{

    vector<int> rank, parent, size;

public:
    disjointset(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findupar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findupar(parent[node]);
    }

    void unionbyrank(int u, int v)
    {
        int up_u = findupar(u);
        int up_v = findupar(v);
        if (up_u == up_v)
            return;
        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else if (rank[up_v] < rank[up_u])
        {
            parent[up_v] = up_u;
        }
        else
        {
            parent[up_u] = up_v;
            rank[up_u]++;
        }
    }

    void unionbysize(int u, int v)
    {
        int up_u = findupar(u);
        int up_v = findupar(v);
        if (up_u == up_v)
            return;
        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += up_v;
        }
    }

    int getSize(int node)
    {
        return size[findupar(node)];
    }
};

int main()
{
    disjointset ds(7);
    ds.unionbysize(1, 2);
    ds.unionbysize(2, 3);
    ds.unionbysize(4, 5);
    ds.unionbysize(6, 7);
    ds.unionbysize(5, 6);

    if (ds.findupar(3) == ds.findupar(7))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }

    ds.unionbysize(3, 7);

    if (ds.findupar(3) == ds.findupar(7))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }

    cout << ds.getSize(3) << endl;

    return 0;
}