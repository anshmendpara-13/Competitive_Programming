#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// const int M = 1e9 + 7;
const int M = 1337;


int binExpRecur(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }

    // long long res = binExpRecur(a, b / 2);
    int res = binExpRecur(a, b / 2);

    if (b & 1)
    {
        // return a * ((res * res) % M);
        return a * ((res * 1LL * res) % M);
    }
    else
    {
        // return ((res * res) % M);
        return ((res * 1LL * res) % M);
    }
}

int binExpIter(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

int main()
{

    // cout << pow(2, 3) << endl; // return double value but double not accurate so not use in cp

    // double maxRange = numeric_limits<double>::max();
    // cout << "Maximum range in scientific notation: " << scientific << maxRange << endl;

    // long long maxRange_long_long = numeric_limits<long long>::max();
    // cout << "Maximum range of long long in scientific notation: " << scientific << static_cast<double>(maxRange_long_long) << std::endl;

    // iterative or recursive to find a^b **************

    // normal code **************** O(m)

    int n, m;
    cin >> n >> m;
    int ans = 1;
    for (int i = 0; i < m; i++)
    {
        ans *= n;
        ans %= M;
    }
    cout << ans << endl;

    // recursive code ***************** log(m)

    // int n, m;
    // cin >> n >> m;
    cout << binExpRecur(n, m) << endl;

    // iterative code ******************* log(m)

    // int n, m;
    // cin >> n >> m;
    cout << binExpIter(n, m) << endl;

    return 0;
}