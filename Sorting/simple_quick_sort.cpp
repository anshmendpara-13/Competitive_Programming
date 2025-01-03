#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    // left and right part
    int i = s, j = e;

    while (i < j)
    {
        while (i < e && arr[i] <= pivot)
        {
            i++;
        }
        while (j > s && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[s], arr[j]);
    return j;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s < e)
    {

        int p = partition(arr, s, e);

        // left part sort
        quickSort(arr, s, p - 1);

        // right part sort
        quickSort(arr, p + 1, e);
    }
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

    // pick one element and store in right place, left side element are less and right side elements are greater
    // we use partition method to sort the array.

    // sort(arr,arr+n);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // cout <<  <<endl;
    return 0;
}