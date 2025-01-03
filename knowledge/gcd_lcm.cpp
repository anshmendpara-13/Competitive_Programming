#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int gcd(int a, int b)
{
    // remainder a%b
    // int rem = a % b;

    // if (rem == 0)
    // {
    //     return b;
    // }
    // return gcd(b, rem);

    // Or.. ******
    // if (b == 0)
    //     return a;
    // return gcd(b, a % b);

    // Or.. ******
    return __gcd(a, b);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << "gcd: " << gcd(n, m) << endl;
    cout << "lcm: " << (n * m) / gcd(n, m) << endl;

    // find minimum fraction a/b = (a/gcd(a,b)) / (b/gcd(a,b))
    return 0;
}