#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1[0] > nums2[nums2.size() - 1] || nums2[0] > nums1[nums1.size() - 1])
    {
        return -1;
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                return nums1[i];
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    int m;
    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }

    cout << getCommon(nums1, nums2) << endl;
    return 0;
}