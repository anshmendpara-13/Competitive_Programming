#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 1e6;
int n, cows;
int positions[N];

bool canPlaceCow(int mindist)
{
    int laspos = -1;
    int cows_cnt = cows;
    sort(positions, positions + n);
    for (int i = 0; i < n; i++)
    {
        if (positions[i] - laspos >= mindist || laspos == -1)
        {
            cows_cnt--;
            laspos = positions[i];
        }
        if (cows_cnt == 0)
        {
            return true;
        }
    }
    return cows_cnt == 0;
}
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> cows;
        for (int i = 0; i < n; i++)
        {
            cin >> positions[i];
        }

        int lo = 0, hi = 0, mid;
        for (int i = 0; i < n; i++)
        {
            hi = max(hi, positions[i]); // Find the maximum position
        }
        // int ct = 0;   
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (canPlaceCow(mid))
            {
                lo = mid;
                // ct++;
            }
            else
            {
                hi = mid - 1;
                // ct++;
            }
        }

        if (canPlaceCow(hi))
        {
            cout << hi << endl;
        }
        else
        {
            cout << lo << endl;
        }
        // cout << ct << endl; 
    }

    // TC =  log(10^9)*N   -->> (log(10^9) == 35)
    return 0;
}