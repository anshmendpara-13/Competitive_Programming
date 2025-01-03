#include <bits/stdc++.h>
using namespace std;

int binary_search_max(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;

    while (s < e)
    {
        int mid = s + ((e - s) / 2);
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s;
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

    cout << binary_search_max(arr) << endl;

    return 0;
}
