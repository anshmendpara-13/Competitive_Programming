#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool ispoweroftwo(int num)
{
    if (num == 0)
    {
        return false;
    }

    return ceil(log2(num)) == floor(log2(num));
}

int main()
{
    int n;
    cin >> n;
    ispoweroftwo(n) ? cout << "yes" << endl : cout << "no" << endl;
    return 0;
}