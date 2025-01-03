#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool isPossible(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int lasPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lasPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lasPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = *max_element(stalls.begin(), stalls.end());
    int e = maxi;

    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;
    
    vector<int> stalls(n);

    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    cout << aggressiveCows(stalls, k) << endl;

    return 0;
}