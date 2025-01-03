#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool isValid(string s)
{
    stack<char> stk;
    for (auto ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stk.push(ch);
        }
        else
        {
            if (stk.empty())
            {
                return false; // Stack is empty but closing bracket encountered
            }
            char top = stk.top();
            stk.pop();
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{'))
            {
                return false; // Mismatched closing bracket
            }
        }
    }
    return stk.empty(); // Check if stack is empty after processing all characters
}

int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}