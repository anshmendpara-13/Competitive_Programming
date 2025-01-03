// SV -> L2

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int func(vector<int> &arr, int &k)
{
    int lsum = 0, rsum = 0, maxsum = 0;

    int summm = accumulate(arr.begin(), arr.begin() + k, 0);
    maxsum = max(maxsum, summm);

    for (int i = 0; i < k; i++)
    {
        summm -= arr[k - i - 1];
        summm += arr[arr.size() - i - 1];
        maxsum = max(maxsum, summm);
    }
    return maxsum;
}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << func(arr, k) << endl;

    return 0;
}