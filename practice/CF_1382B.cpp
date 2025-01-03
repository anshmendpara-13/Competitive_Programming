#include <iostream>
using namespace std;
int main()
{
    int n, c, i, t;
    cin >> t;
    while (t--)
    {
        c = 0;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < n; i++)
        {
            if (a[i] == 1)
                c++;
            else
                break;
        }
        if (c == n)
            c--;
        if (c % 2 == 1)
            cout << "Second" << endl;
        else
            cout << "First" << endl;
    }
}