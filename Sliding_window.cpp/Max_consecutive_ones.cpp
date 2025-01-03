#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int func(vector<int> &v, int &k) // O(2*n)
{
    int maxlen = 0, l = 0, r = 0, zeros = 0;

    while (r < v.size())
    {
        if (v[r] == 0)
            zeros++;

        while (zeros > k)
        {
            if (v[l] == 0)
                zeros--;
            l++;
        }

        maxlen = max(maxlen, (r - l + 1));
        r++;
    }
    return maxlen;
}

int func1(vector<int> &v, int k) // O(n)
{
    int l = 0, r = 0, zeros = 0, maxlen = INT_MIN;

    while (r < v.size())
    {
        if (v[r] == 0)
            zeros++;
        if (zeros > k)
        {
            if (v[l] == 0)
                zeros--;
            l++;
        }
        if (zeros <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // cout << func(v, k) << endl;
    cout << func1(v, k) << endl;

    return 0;
}