#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int func(vector<int> &arr, int k)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) // O(N^2)
    {
        map<int, int> mp; // S(N)
        for (int j = i; j < arr.size(); j++)
        {
            mp[arr[j]]++;

            if (mp.size() == k)
            {
                cnt++;
            }
            if (mp.size() > k)
            {
                break;
            }
        }
    }
    return cnt;
}

int func1(vector<int> arr, int k)
{
    int cnt = 0, l = 0, r = 0;
    map<int, int> mp;

    while (r < arr.size())
    {
        mp[arr[r]]++;

        while (mp.size() > k)
        {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0)
            {
                mp.erase(arr[l]);
            }
            l++;
        }
        cnt = cnt + (r - l + 1);
        r++;
    }

    return cnt;
}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << func(arr, k) << endl;
    cout << func1(arr, k) - func1(arr, (k - 1)) << endl;

    return 0;
}