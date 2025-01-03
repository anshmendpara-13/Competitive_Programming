#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    // ll n;
    // cin >> n;
    // int a[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    // sort(a, a + n);

    // for (auto &&i : a)
    // {
    //     cout << i << " ";
    // }

    // cout << endl;

    // int *ptr = lower_bound(a + 7, a + n, 5);
    // if (ptr == (a + n))
    // {
    //     cout << "NOT FOUND" << endl;
    //     return 0;
    // }
    // cout << *ptr << endl;

    // cout << endl;
    // int *ptr1 = upper_bound(a, a + n, 7);
    // cout << *ptr1 << endl;

    // ***********************************************

    // ll n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    // sort(a.begin(), a.end());

    // for (auto &&i : a)
    // {
    //     cout << i << " ";
    // }

    // auto it = upper_bound(a.begin(), a.end(), 5);
    // // auto it = lower_bound(a.begin(), a.end(), 8);

    // if (it == a.end())
    // {
    //     cout << "NOT FOUND" << endl;
    //     return 0;
    // }
    // cout << endl;
    // cout << *it << endl;

    // *************************************************

    ll n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    for (auto &&i : s)
    {
        cout << i << " ";
    }

    // auto it = lower_bound(s.begin(), s.end(), 5); // this is O(n) in case of set or map
    // cout << *it << endl;

    cout << endl;
    auto it = s.lower_bound(7);
    cout << *it << endl;

    return 0;
}