#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// int sttoint(string s)
// {
//     int final = 0;
//     int base = 1;
//     for (int i = s.length() - 1; i >= 0; i--)
//     {
//         int x = s[i] - '0';
//         final += x * base;
//         base *= 10;
//     }
//     return final;
// }

// string largestOddNumber(string num)
// {
//     int maxi = -1;
//     for (int i = 0; i < num.length(); i++)
//     {
//         for (int j = 0; j <= num.length(); j++)
//         {
//             string st = num.substr(i, j);
//             if (st == "")
//             {
//                 continue;
//             }
//             int ss = sttoint(st);
//             if (ss & 1)
//             {
//                 maxi = max(maxi, ss);
//             }
//         }
//     }
//     if (maxi == -1)
//         return "";
//     return to_string(maxi);
// }

string largestOddNumber(string num)
{
    if (num.back() % 2 == 1)
        return num;
    int i = num.length() - 1;
    while (i >= 0)
    {
        int n = num[i];
        if (n % 2 == 1)
            return num.substr(0, i + 1);
        i--;
    }
    return "";
}
int main()
{
    string s;
    cin >> s;

    string ans = largestOddNumber(s);
    cout << ans << endl;
    return 0;
}