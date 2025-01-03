#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int lower_bound_find(vector<int> &arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    if (arr[s] >= target)
    {
        return arr[s];
    }
    if (arr[e] >= target)
    {
        return arr[e];
    }
    return -1;
}

int upper_bound_find(vector<int> &arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] <= target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    if (arr[s] > target)
    {
        return arr[s];
    }
    if (arr[e] > target)
    {
        return arr[e];
    }
    return -1;
}

int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n);


    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> target;

    cout << lower_bound_find(arr, target) << endl;
    cout << upper_bound_find(arr, target) << endl;
    return 0;
}