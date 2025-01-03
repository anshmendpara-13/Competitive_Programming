#include <bits/stdc++.h>

using namespace std;

void print_s(set<string> &s)
{
    for (auto &&i : s)
    {
        cout << i << endl;
    }
}

int main()
{
    set<string> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    print_s(s);

    return 0;
}