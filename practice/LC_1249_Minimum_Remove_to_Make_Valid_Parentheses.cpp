#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string minRemoveToMakeValid(string s)
{
    int leftct = 0;
    int rightct = 0;
    stack<char> stack;

    for (char ch : s)
    {
        if (ch == '(')
        {
            leftct++;
        }
        else if (ch == ')')
        {
            rightct++;
        }
        if (rightct > leftct)
        {
            rightct--;
            continue;
        }
        else
        {
            stack.push(ch);
            // cout << ch << endl;
        }
    }

    string result = "";

    while (!stack.empty())
    {
        char curr = stack.top();
        stack.pop();
        // cout << curr << endl;
        if (leftct > rightct && curr == '(')
        {
            leftct--;
        }
        else
        {
            result += curr;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{

    string s;
    cin >> s;
    cout << minRemoveToMakeValid(s) << endl;
    return 0;
}