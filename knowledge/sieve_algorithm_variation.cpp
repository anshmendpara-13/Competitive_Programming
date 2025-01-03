#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 7;

vector<bool> isprime(N, 1);
vector<int> LP(N, 0);
vector<int> HP(N, 0);

vector<int> divisors[N];
int sum[N];

int main()
{

    // for store lp, hp, isprime ***************************** N*log(log(n))
    // isprime[0] = isprime[1] = false;
    // for (int i = 2; i < N; i++)
    // {
    //     if (isprime[i] == true)
    //     {
    //         for (int j = 2 * i; j < N; j += i)
    //         {
    //             isprime[j] = false;
    //             HP[j] = i;
    //             if (LP[j] == 0)
    //             {
    //                 LP[j] = i;
    //             }
    //         }
    //     }
    // }

    // for store all divisors ************************************** N*log(N)
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisors[j].push_back(i);
            sum[j] += i;
        }
    }

    // lowest prime and highest prime ***************************
    // int n;
    // cin >> n;
    // cout << LP[n] << " " << HP[n] << endl;

    // vector<int> prime_factors;
    // map<int, int> prime_factors;
    // while (n > 1)
    // {
    //     int prime_factor = HP[n];
    //     while (n % prime_factor == 0)
    //     {
    //         n /= prime_factor;
    //         // prime_factors.push_back(prime_factor);
    //         prime_factors[prime_factor]++;
    //     }
    // }

    // for (auto val : prime_factors)
    // {
    //     cout << val << " ";
    // }
    // cout << endl;

    // for (auto i : prime_factors)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    // ***************************************************************

    // divisor untill n **********************************************
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (auto val : divisors[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << sum[i] << endl;
    }
    cout << endl;

    return 0;
}