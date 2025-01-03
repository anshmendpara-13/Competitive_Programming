#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int fen[N];

void update(int i, int add)
{
    while (i > 0 && i < N)
    {
        fen[i] += add;
        i += (i & (-i));
    }
}

int sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += fen[i];
        i -= (i & (-i));
    }
    return s;
}

void clearFenwick()
{
    fill(fen, fen + N, 0);
}

int findKthSmallest(int k)
{
    int low = 1, high = N - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (sum(mid) >= k)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
    // {
    clearFenwick();
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        update(num, 1);
    }

    while (q--)
    {
        int x;
        cin >> x;

        if (x > 0)
        {
            update(x, 1);
        }
        else
        {
            x = -x;
            int toRemove = findKthSmallest(x);
            update(toRemove, -1);
        }
    }

    int totalElements = sum(N - 1);
    if (totalElements == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int smallest = findKthSmallest(1);
        cout << smallest << endl;
    }
    // }

    return 0;
}
