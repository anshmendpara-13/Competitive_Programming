#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool canThreePartsEqualSum(vector<int> &arr)
{
    int n = arr.size();
    int zero_ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero_ct++;
        }
    }
    if (zero_ct == n)
    {
        return true;
    }

    int x = accumulate(arr.begin(), arr.end(), 0);
    if (x % 3 != 0)
        return false;

    int we_want_sum = x / 3;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == we_want_sum)
        {
            cnt++;
            sum = 0;
        }
    }
    if (cnt == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << canThreePartsEqualSum(v) << endl;
    return 0;
}