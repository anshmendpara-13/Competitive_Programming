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

int main()
{
    // in monotonic function we apply binary search
    // we want in O(log(n))

    // mid condition to find pivot element

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pivot = getPivot(arr, n);
    cout << pivot << endl;

    return 0;
}