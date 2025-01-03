#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        string str;
        getline(cin, str);

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                cout << endl;
            }
            else
            {
                cout << char(toupper(str[i]));
            }
        }
    }

    // cout <<  <<endl;
    return 0;
}