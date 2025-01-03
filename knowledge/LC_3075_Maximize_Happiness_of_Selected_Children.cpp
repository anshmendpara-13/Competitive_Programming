#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

long long maximumHappinessSum(vector<int> &happiness, int k)
{
    long long ans = 0;
    long long size = happiness.size();
    sort(happiness.begin(), happiness.end(), [](long long a, long long b)
         { return a > b; });

    for (long long i = 0; i < k; i++)
    {
        if ((happiness[i] - (1 * (i))) > 0)
        {
            ans = ans + happiness[i] - (1 * (i));
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> happiness(n);
    for (int i = 0; i < n; i++)
    {
        cin >> happiness[i];
    }

    int k;
    cin >> k;
    ll ans = maximumHappinessSum(happiness, k);
    cout << ans << endl;

    return 0;
}