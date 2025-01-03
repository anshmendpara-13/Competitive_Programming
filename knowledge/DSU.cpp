#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e2 + 7;
int parent[N];
int size[N];

void make(int v)
{
    size[v] = 1;
    parent[v] = v;
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
            size[b] += size[a];
        }
        else
        {
            parent[b] = a;
            size[a] += size[b];
        }
    }
}

/*
time complexity
O(alpha(n)) - > alpha(n) -> reverse ackerman function ; value increase very slow
called Amotorise time
*/
int main()
{
    /*
        making set
        In DSU have 3 function
        make -> add new node
        find -> return parent of group
        union -> merge two groups
    */

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    while (k--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int connected_ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            connected_ct++;
    }

    cout << connected_ct << endl;

    return 0;
}