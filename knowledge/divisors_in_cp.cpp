#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    int sum = 0;
    for (int i = 1; i * i <= n; i++) // O(root(n))
    {
        if (n % i == 0)
        {
            cnt += 1;
            sum += i;
            if (i != n / i)
            {
                sum += n / i;
                cnt += 1;
            }

            cout << i << " " << n / i << endl;
        }
    }

    cout << sum << endl;
    cout << cnt << endl;

    // formula

    return 0;
}