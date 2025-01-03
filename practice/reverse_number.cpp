#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    long ans = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        n /= 10;
        ans = (ans * 10) + lastdigit;
    }
    cout << ans << endl;
    return 0;
}