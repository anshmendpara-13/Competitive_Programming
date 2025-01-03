#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    // if (n == 1)
    // {
    //     cout << 0 << endl;
    //     return 0;
    // }

    // bool is_prime = true;
    // for (int i = 2; i * i < n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         is_prime = 0;
    //         break;
    //     }
    // }
    // cout << is_prime << endl;

    // prime factors *******************************************
    vector<int> prime_factors;
    int i;
    for (i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        prime_factors.push_back(n);
    }

    for (auto val : prime_factors)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}