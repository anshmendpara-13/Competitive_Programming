#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 1e2 + 7;
int parent[N];
int size[N];
multiset<int> sizes;

void merge(int a, int b)
{
    sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.find(size[b]));
    sizes.insert(size[a] + size[b]);
}

void make(int v)
{
    size[v] = 1;
    parent[v] = v;
    sizes.insert(1);
}

int find(int v)
{
    if (v == parent[v])
        return v;
    // below line is path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    // size(current tree size) and rank(depth): for merge the tree
    // below line is union by rank : take the smaller one
    if (a != b)
    {
        if (size[a] > size[b])
        {
            parent[a] = b;
            merge(a, b);
            size[b] += size[a];
        }
        else
        {
            parent[b] = a;
            merge(a, b);
            size[a] += size[b];
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
        if (sizes.size() == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());
            cout << mx - mn << endl;
        }
    }
    

    return 0;
}