#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<string> valid;

void generate(string &s, int open, int close)
{
    if (open == 0 && close == 0)
    {
        valid.push_back(s);
        return;
    }

    // we do pop_back() we undo the previous state so this not effect previous call or next call

    if (open > 0)
    {
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back();
    }
    if (close > 0)
    {
        if (open < close)
        {
            s.push_back(')');
            generate(s, open, close - 1);
            s.pop_back();
        }
    }
}
int main()
{
    // jab opening brecket jyada hogi tab ham closing bracket dalege && we also have closing brecket
    string s = "";
    int n;
    cin >> n;
    generate(s, n, n);
    for (auto &&i : valid)
    {
        cout << i << endl;
    }

    return 0;
}