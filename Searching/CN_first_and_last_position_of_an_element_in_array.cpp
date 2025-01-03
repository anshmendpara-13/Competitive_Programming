#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int firstOccurence(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + ((e - s) / 2);

    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            // cout << mid << endl;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            // right part me jao
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            // left part me jao
            e = mid - 1;
        }
        mid = s + ((e - s) / 2);
    }
    return ans;
}
int lastOccurence(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + ((e - s) / 2);

    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            // cout << mid << endl;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            // right part me jao
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            // left part me jao
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

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << "first occurence of " << key << " is " << firstOccurence(arr, n, key) << " and last occurence is " << lastOccurence(arr, n, key) << endl;
    cout << "total occurence : " << lastOccurence(arr, n, key) - firstOccurence(arr, n, key) + 1 << endl;

    return 0;
}