#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;

        int total = 1;

        for (int i = 0; i < num; i++)
        {
            int temp;
            cin >> temp;
            total *= temp;
        }
        if ((total % 10 == 2) || (total % 10 == 3) || (total % 10 == 5))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    // cout <<  <<endl;
    return 0;
}