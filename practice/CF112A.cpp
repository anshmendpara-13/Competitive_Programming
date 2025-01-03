#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int count = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (int(tolower(s1[i])) > int(tolower(s2[i])))
        {
            count++;
            break;
        }
        else if (int(tolower(s1[i])) < int(tolower(s2[i])))
        {
            count--;
            break;
        }
    }
    if (count > 0)
    {
        cout << "1" << endl;
    }
    else if (count < 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    // cout <<  <<endl;
    return 0;
}