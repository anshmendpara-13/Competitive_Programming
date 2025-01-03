#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    bool flag = false;
    // cout << str.size() << endl;

    for (int i = 0; i < str.size() / 2; i++)
    {
        // cout << str[i] << " " << str[str.size() - i - 1] << endl;
        if (str[i] != str[str.size() - i - 1])
        {
            cout << "NO" << endl;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "YES" << endl;
    }

    return 0;
}