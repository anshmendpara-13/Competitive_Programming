#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 0, r = 0, sum = 0, maxlen = 0;

    // while (r < v.size())  // O(n^2)
    // {
    //     sum += v[r];

    //     while (sum > k)
    //     {
    //         sum -= v[l];
    //         l++;
    //     }
    //     if (sum <= k)
    //     {
    //         maxlen = max(maxlen, r - l + 1);
    //     }
    //     r++;
    // }

    while (r < v.size()) // O(n)
    {
        sum += v[r];

        if (sum > k)
        {
            l++;
        }
        if (sum <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }

    cout << maxlen << endl;

    return 0;
}