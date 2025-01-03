#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int getPivot(vector<int> &arr, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }

    return s;
}

int binary_search(vector<int> arr, int s, int e, int key)
{
    int index;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else
    {
        if (key > arr[mid])
        {
            index = binary_search(arr, mid + 1, e, key);
            return index;
        }
        else if (key < arr[mid])
        {
            index = binary_search(arr, s, mid - 1, key);
            return index;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int pivot = getPivot(arr, n);
    // cout << pivot << endl;

    int index;

    if (arr[pivot] <= k && k <= arr[n - 1])
    {
        index = binary_search(arr, pivot, n - 1, k);
    }
    else
    {
        index = binary_search(arr, 0, pivot - 1, k);
    }

    cout << index << endl;
    return 0;
}