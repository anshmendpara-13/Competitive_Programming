#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int space = i-1;
        while (space)
        {
            cout << " ";
            space--;
        }

        int j = 1;
        while (j <= (n-i+1))
        {
            // cout << "*"
            //      << " ";
            cout << "*";
            j += 1;
        }
        cout << endl;
        i += 1;
    }

    // cout <<  <<endl;
    return 0;
}