#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void reverse(int l, int r, vector<int> &v)
{
    if (l >= r)
        return;
    swap(v[l++], v[r--]);
    reverse(l, r, v);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (auto val : v)
    {
        cout << val << " ";
    }

    reverse(0, n - 1, v);
    cout << endl;

    for (auto val : v)
    {
        cout << val << " ";
    }

    return 0;
}