#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool ispalindrome(int l, int r, string s)
{
    if (l >= r)
        return true;

    if (s[l] != s[r])
        return false;

    return ispalindrome(l + 1, r - 1, s);
}

int main()
{
    string s;
    cin >> s;

    bool ans = ispalindrome(0, s.length() - 1, s);
    cout << ans << endl;

    return 0;
}