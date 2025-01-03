#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

double precision = 1e-6;

double multiply(double mid, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
    }
    return ans;
}

double nth_root_of_(double &num, int &nth)
{

    double s = 1;
    double e = num;
    double mid;

    while ((e - s) > precision)
    {
        mid = (s + e) / 2;
        if (multiply(mid, nth) < num)
        {
            s = mid;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}
int main()
{
    double num;
    int nth;
    cin >> num >> nth;

    double ans = nth_root_of_(num, nth);
    cout << ans << endl;

    // cout << pow(n, 1.0 / 2) << endl;

    // TC = p*log(n*(10^d))  -->> pth root of number, d decimal accuracy

    return 0;
}