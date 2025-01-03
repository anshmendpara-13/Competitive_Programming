// sum of array
// sum(n,a) -->> sum of elements in array a uptill n index
// sum(n,a) = a[n] + sum[n-1,a];

#include <bits/stdc++.h>

using namespace std;

int sum(int n, int a[])
{
    if (n < 0)
    {
        return 0;
    }

    return sum(n - 1, a) + a[n];
}

int digit_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return digit_sum(n / 10) + n % 10;
}

int main()
{
    int n;
    cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    // cout << sum(n-1, a) << endl;
    cout << digit_sum(n) << endl;

    // cout <<  <<endl;
    return 0;
}