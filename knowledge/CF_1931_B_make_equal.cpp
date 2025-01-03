#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll arr[n];

        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        ll avg = sum / n;
        bool flag = false;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] < avg)
            {
                cout << "NO" << endl;
                flag = true;
                break;
            }

            arr[i + 1] += arr[i] - avg;
            arr[i] = avg;
        }
        if (!flag)
            cout << "YES" << endl;
    }

    return 0;
}