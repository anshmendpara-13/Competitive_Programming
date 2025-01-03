#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int func(vector<int> &arr, int k)
{
    if (k < 0)
        return 0;
    int l = 0, r = 0, sum = 0, cnt = 0;
    while (r < arr.size()) // Change condition from <= to <
    {
        sum += arr[r];

        while (sum > k)
        {
            sum -= arr[l];
            l++;
        }
        cnt = cnt + (r - l + 1);
        r++;
    }
    return cnt;
}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] %= 2;
    }

    cout << func(arr, k) - func(arr, k - 1) << endl;

    return 0;
}