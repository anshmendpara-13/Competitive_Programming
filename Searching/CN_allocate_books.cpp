// book allocation problem
// we have a array of no of book
// student m
// no of book n
// if question have min max allocation then this approach is best

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = accumulate(arr.begin(), arr.end(), 0);

    int s = 0;
    int e = sum;

    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            // cout << s << endl; 
        }

        mid = s + (e - s) / 2;
    }

    cout << ans << endl;

    return 0;
}
