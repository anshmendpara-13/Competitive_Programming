#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int len;
        cin >> len;
        cin.ignore();

        string str;
        getline(cin, str);
        reverse(str.begin(), str.end());

        int total = 0;
        int power2 = 1;

        for (int i = 0; i < str.size(); i++)
        {
            total = total + ((str[i] - '0') * power2);
            power2 *= 2;
        }
        cout << total << endl;
    }

    // cout <<  <<endl;
    return 0;
}