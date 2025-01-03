#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str[n];
    int final_value = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (str[i] == "++X")
        {
            final_value++;
        }
        else if (str[i] == "X++")
        {

            final_value++;
        }
        else if (str[i] == "X--")
        {

            final_value--;
        }
        else if (str[i] == "--X")
        {

            final_value--;
        }
    }
   cout << final_value << endl; 

    return 0;
}