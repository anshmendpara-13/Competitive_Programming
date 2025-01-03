#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// const long long M = 1e9 + 7; // for binExp first
// const long long M = 1e18 + 7; // for binMultiply second
const long long M = 1e18 + 7; // for binMultiply third
                          // long long max 10^18

// below code not work on large a range and M range
// if a range high so we first do (a%M) at initially and do another operations
// if M range high so we not do multiplication we do addition to find answer

// first *********************************************

// int binExp(long long a, long long b)
// {
//     // a = (a % M);
//     int ans = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//         {
//             ans = (ans * 1LL * a) % M;
//         }
//         a = (a * 1LL * a) % M;
//         b >>= 1;
//     }
//     return ans;
// }

// second ********************************************

// long long binMultipy(long long a, long long b)
// {
//     long long ans = 0;
//     while (b > 0)
//     {
//         if (b & 1)
//         {
//             ans = (ans + a) % M;
//         }
//         a = (a + a) % M;
//         b >>= 1;
//     }
//     return ans;
// }

// long long binExp(long long a, long long b)
// {
//     a = (a % M);
//     long long ans = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//         {
//             ans = binMultipy(ans, a) % M;
//         }
//         a = binMultipy(a, a) % M;
//         b >>= 1;
//     }
//     return ans;
// }

// third *************************************************

// ***********************************************************************************************************
// 50^64^32 -->> use coprime, ETF(Extended Euclidean algorithm), Fermat's Little Theorem.
// ((a^b) % M) = (a^(b%Φ(M)) % M)
// Φ(M) = M* ∏(1-(1/p)) ; p = prime number
//////////  n|p = all co-prime number less then M   ex... M = 6 -> so coprime number is 1,5

// if M is prime
// ((a^b) % M) = (a^(b%(M-1)) % M)
// ***********************************************************************************************************

int binExp(long long a, long long b, int m)
{
    int ans = 1;
    while (b > 0) // loop run log(b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    // 60 ^ 64 ^ 32 % M
    cout << binExp(a, binExp(b, c, M - 1), M) << endl;
    return 0;
}