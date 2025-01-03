#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int firstOccurence(vector<int> arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + ((e - s) / 2);

    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        mid = s + ((e - s) / 2);
    }
    return ans;
}
int lastOccurence(vector<int> arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + ((e - s) / 2);

    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        mid = s + ((e - s) / 2);
    }
    return ans;
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

    int key;
    cin >> key;

    pair<int, int> pair;
    if (arr.size() == 0)
    {
        pair.first = -1;
        pair.second = -1;
    }

    pair.first = firstOccurence(arr, n, key);
    pair.second = lastOccurence(arr, n, key);

    cout << pair.first << " " << pair.second << endl;

    // auto lb = lower_bound(arr.begin(), arr.end(), key);
    // auto ub = upper_bound(arr.begin(), arr.end(), key);
    // int llb = distance(arr.begin(), lb);
    // int lub = distance(arr.begin(), ub);
    // cout << llb << " "<< lub -1 << endl;

    return 0;
}