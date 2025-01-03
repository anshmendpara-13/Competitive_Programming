#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool allbitsareSet(int num)
{
    if ((((num + 1) & num) == 0))
    {
        return true;
    }
    return false;
}

bool BitsAreAltOrder(unsigned int n)
{
    unsigned int num = n ^ (n >> 1);

    return allbitsareSet(num);
}

int main()
{
    unsigned int n;
    cin >> n;

    if (BitsAreAltOrder(n))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}