#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int dp[1007][1007];
int func(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // remove 1 char from s1
    int ans = func(i - 1, j, s1, s2);
    // remove 1 char from s2
    ans = max(ans, func(i, j - 1, s1, s2));
    // remove 1 char from s1 and s2
    ans = max(ans, func(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));

    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    memset(dp, -1, sizeof(dp));
    return func(text1.length() - 1, text2.length() - 1, text1, text2);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int ans = longestCommonSubsequence(s1, s2);
    cout << ans << endl;

    return 0;
}