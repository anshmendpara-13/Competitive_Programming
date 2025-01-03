#include <bits/stdc++.h>

using namespace std;

vector<string> s;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        int size = x * y;
        char charArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        string str = "";
        for (int i = 0; i < y; i++)
        {
            str += charArray[i];
        }
        cout << endl;

        for (int i = 0; i < x ; i++)
        {
            cout << str; 
        }

   
    }

    // cout <<  <<endl;
    return 0;
}