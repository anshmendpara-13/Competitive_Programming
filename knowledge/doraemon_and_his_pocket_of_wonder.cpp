#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n;
        multiset<int> gadgets;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            gadgets.insert(x);
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            int count_x = gadgets.count(x);
            while (count_x--)
            {
                cout << x << " ";
            }
            gadgets.erase(x);
        }
        for (auto gadget : gadgets)
        {
            cout << gadget << " ";
        }
        cout << endl;
    }

    return 0;
}