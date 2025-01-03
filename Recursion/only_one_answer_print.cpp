#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool print(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            return true;
        }
        else
            return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if (print(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    s -= arr[ind];
    ds.pop_back();

    if (print(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    return false;
}

int main()
{
    int arr[] = {1, 2, 1};
    vector<int> ds;

    print(0, ds, 0, 2, arr, 3);

    return 0;
}