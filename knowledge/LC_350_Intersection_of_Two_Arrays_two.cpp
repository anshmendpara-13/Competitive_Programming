#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> result;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> num1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
    }
    int m;
    cin >> m;
    vector<int> num2(n);
    for (int i = 0; i < m; i++)
    {
        cin >> num2[i];
    }

    vector<int> ans = intersect(num1, num2);
    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}