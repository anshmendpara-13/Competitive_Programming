#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int print(int ind, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
            return 1;
        else
            return 0;
    }

    // s += arr[ind];
    int l = print(ind + 1, s + arr[ind], sum, arr, n);
    // s -= arr[ind];

    int r = print(ind + 1, s, sum, arr, n);

    return l + r;
}

int main()
{

    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;

    cout << print(0, 0, sum, arr, n) << endl;

    return 0;
}