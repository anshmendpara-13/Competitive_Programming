#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // sort(arr, arr + n); // in this we give a range also ->> into sort ->> 3 sorting algo mix ->> quick, heap, insertion sort
    // for (auto &&i : arr)
    // {
    //     cout << i << " ";
    // }

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    for (auto &&i : a)
    {
        cout << i << " ";
    }

    // cout <<  <<endl;
    return 0;
}