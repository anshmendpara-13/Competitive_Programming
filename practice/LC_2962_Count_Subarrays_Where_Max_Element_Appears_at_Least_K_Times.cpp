#include <bits/stdc++.h>

using namespace std;

long long countSubarrays(std::vector<int> &nums, int k)
{
    long long ans = 0;
    int n = nums.size();
    int maxNum = *std::max_element(nums.begin(), nums.end());

    int left = 0, right = 0, count = 0;

    while (right < n)
    {
        if (nums[right] == maxNum)
            count++;

        while (count >= k)
        {
            if (nums[left] == maxNum)
                count--;
            left++;
            ans += n - right;
        }
        right++;
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {28, 5, 58, 91, 24, 91, 53, 9, 48, 85, 16, 70, 91, 91, 47, 91, 61, 4, 54, 61, 49};
    int k1 = 1;
    cout << countSubarrays(nums1, k1) << endl;

    return 0;
}
