#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    // x^x = 0
    // x^0 = x

    /*
        given array a of n integers. all integers are present in event count except one.
        find that one integer which has odd count in O(N) time complexity and O(1) space;
     */

    int n;
    cin >> n;

    int ans = 0;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans ^= x;
    }

    cout << ans << endl;
    return 0;
}