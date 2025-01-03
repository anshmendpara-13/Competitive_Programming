#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    string str;
    string str2 = countAndSay(n - 1);
    int ct;
    for (int i = 0; i < str2.size(); i += ct)
    {
        char k = str2[i];
        ct = 0;
        for (int j = i; str2[j] == k; j++)
        {
            ct++;
        }
        str += to_string(ct);
        str += str2[i];
        // cout << str << endl;
    }
    return str;
}
int main()
{
    int n;
    cin >> n;
    countAndSay(n);
    // cout << countAndSay(n) << endl;
    return 0;
}