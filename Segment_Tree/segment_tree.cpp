#include <iostream>
#include <vector>
using namespace std;

void buildTree(vector<int> &tree, const vector<int> &arr, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        buildTree(tree, arr, 2 * node + 1, start, mid);
        buildTree(tree, arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

void updateTree(vector<int> &tree, vector<int> &arr, int node, int start, int end, int idx, int value)
{
    if (start == end)
    {
        arr[idx] = value;
        tree[node] = value;
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
        {
            updateTree(tree, arr, 2 * node + 1, start, mid, idx, value);
        }
        else
        {
            updateTree(tree, arr, 2 * node + 2, mid + 1, end, idx, value);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

int queryTree(const vector<int> &tree, int node, int start, int end, int l, int r)
{
    if (r < start || end < l)
    {
        return 0;
    }
    if (l <= start && end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int left_query = queryTree(tree, 2 * node + 1, start, mid, l, r);
    int right_query = queryTree(tree, 2 * node + 2, mid + 1, end, l, r);
    return left_query + right_query;
}

void updaterange(int start, int end, int idx, int l, int r, int val, vector<int> &tree, vector<int> &lazy)
{
    if (lazy[idx] != 0)
    {
        tree[idx] += (r - l + 1) * lazy[idx];
        if (l != r)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (r < start || l > end || l > r)
    {
        return;
    }
    if (l >= start && end >= r)
    {
        tree[idx] += (r - l + 1) * val;
        if (l != r)
        {
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }
        return;
    }
    else
    {
        int mid = l + (r - l) / 2;
        updaterange(start, end, 2 * idx + 1, l, mid, val, tree, lazy);
        updaterange(start, end, 2 * idx + 2, mid + 1, r, val, tree, lazy);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
}

void buildindexbasedsegmenttree(int i, int l, int r, vector<int> tree, vector<int> &arr)
{
    if (l == r)
    {
        tree[i] = l;
        return;
    }
    int mid = l + (r - l) / 2;
    buildindexbasedsegmenttree(2 * i + 1, l, mid, tree, arr);
    buildindexbasedsegmenttree(2 * i + 2, mid + 1, r, tree, arr);

    tree[i] = (arr[tree[2 * i + 1]] >= arr[tree[2 * i + 2]]) ? tree[2 * i + 1] : tree[2 * i + 2];
}

int queryonindexbasedsegmenttree(int start, int end, int i, int l, int r, vector<int> tree, vector<int> &arr)
{
    if (l > end || r < start)
    {
        return -1;
    }
    if (l >= start && r <= end)
    {
        return tree[i];
    }
    int mid = l + (r - l) / 2;
    int leftindex = queryonindexbasedsegmenttree(start, end, 2 * i + 1, l, mid, tree, arr);
    int rightindex = queryonindexbasedsegmenttree(start, end, 2 * i + 2, mid + 1, r, tree, arr);

    if (leftindex == -1)
    {
        return rightindex;
    }
    if (rightindex == -1)
    {
        return leftindex;
    }

    return (arr[leftindex] >= arr[rightindex]) ? leftindex : rightindex;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();
    vector<int> tree(4 * n);

    buildTree(tree, arr, 0, 0, n - 1);

    cout << "Sum of range [1, 3]: " << queryTree(tree, 0, 0, n - 1, 1, 3) << endl;

    updateTree(tree, arr, 0, 0, n - 1, 2, 6);

    cout << "After update, sum of range [1, 3]: " << queryTree(tree, 0, 0, n - 1, 1, 3) << endl;

    int start, end, val;
    cin >> start >> end >> val;
    vector<int> lazy(4 * n, 0);
    //                     idx, start-end : val
    updaterange(start, end, 0, 0, n - 1, val, tree, lazy);

    cout << "After update, sum of range [1, 3]: " << queryTree(tree, 0, 0, n - 1, 1, 3) << endl;

    return 0;
}
