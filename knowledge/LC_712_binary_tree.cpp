#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// int ans(vector<int> nums, int s, int e, int target)
// {
//     int answ = -1;
//     while (s <= e)
//     {
//         int mid = (s + e) / 2;
//         if (nums[mid] == target)
//         {
//             return mid;
//         }
//         else if (nums[mid] > target)
//         {
//             e = mid - 1;
//             answ = ans(nums, s, mid - 1, target);
//         }
//         else
//         {
//             s = mid + 1;
//             answ = ans(nums, mid + 1, e, target);
//         }
//     }
//     return answ;
// }

// int search(vector<int> &nums, int target)
// {
//     return ans(nums, 0, nums.size() - 1, target);
// }

int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int position = -1;

    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (nums[mid] == target)
        {
            position = mid;
            break;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return position;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    cout << search(nums, target) << endl;

    return 0;
}