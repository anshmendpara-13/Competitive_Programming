#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e7 + 7;

vector<bool> isprime(N, 1);

int main()
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i] == true)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isprime[j] = false;
            }
        }
    }

    // time complexity = O(log(log(N)))
    int n;
    cin >> n;
    cout << isprime[n] << endl;

    return 0;
}