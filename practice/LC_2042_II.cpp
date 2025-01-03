#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool areNumbersAscending(string s)
{
    string ss = "";
    int n1, n2 = INT_MIN;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(c))
        {
            ss += c;
        }
        else if (!ss.empty())
        {
            n1 = stoi(ss);
            if (n1 <= n2)
            {
                return false;
            }
            n2 = n1;
            ss = "";
        }
    }

    if (!ss.empty())
    {
        int n1 = stoi(ss);
        if (n1 <= n2)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s;
    getline(cin, s); 
    cout << areNumbersAscending(s) << endl;
    return 0;
}