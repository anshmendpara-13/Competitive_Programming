#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> findTwoElement(vector<int> &arr, int n)
{
    vector<int> ans(2, -1);
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
        {
            ans[1] = i;
        }
        else if (mp[i] == 2)
        {
            ans[0] = i;
        }
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = findTwoElement(arr, n);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}