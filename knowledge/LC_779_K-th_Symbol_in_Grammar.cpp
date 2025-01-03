#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int kthGrammar(int n, int k)
{
    if (n == 1)
        return 0;
    int num = pow(2, n - 1);

    if (k <= num / 2)
    {
        return kthGrammar(n - 1, k);
    }

    if (n % 2 == 0)
    {
        int ans = kthGrammar(n - 1, k - (num / 2));
        if (ans == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        return kthGrammar(n - 1, num - k + 1);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << kthGrammar(n, k) << endl;
    return 0;
}