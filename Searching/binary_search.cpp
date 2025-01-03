#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int binary_search(int arr[], int s, int e, int key)
{
    int index;
    // int mid = (s + e) / 2;

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

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int index = binary_search(arr, 0, n - 1, key);

    if (index < 0)
    {
        cout << "NOT FOUND" << endl;
    }
    else
    {
        cout << "AT " << index + 1 << " POSITION" << endl;
    }

    return 0;
}