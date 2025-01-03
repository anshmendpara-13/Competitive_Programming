#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int search_binary(vector<int> &arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n);

    // log(n)  time complexity for sorting array

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> target;

    cout << search_binary(arr, target) << endl;

    return 0;
}