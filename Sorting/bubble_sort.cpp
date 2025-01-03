#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    // in every step large element go to last position
    int n;
    cin >> n;

    vector<int> arr;
    arr.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int flag = 0;
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        // for round 1 to n-1
        for (int j = 1; j <= n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
            count++;
        }
        if (flag == 0)
        {
            break;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
        // cout << count << endl;
    }

    return 0;
}

// O(n(n-1)/2) time complexity
// O(1) space complexity