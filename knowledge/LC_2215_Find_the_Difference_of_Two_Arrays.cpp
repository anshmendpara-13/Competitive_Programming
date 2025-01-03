#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    set<int> s;
    vector<int> v;
    vector<vector<int>> ans;

    // Insert elements of nums1 and nums2 into the set to remove duplicates
    for (auto i : nums1)
    {
        s.insert(i);
    }
    for (auto j : nums2)
    {
        s.insert(j);
    }

    // Insert elements of the set into the vector
    for (auto val : s)
    {
        v.push_back(val);
    }

    // Remove elements from v that are also present in nums1
    vector<int> vcopy = v;
    for (int i = 0; i < nums1.size(); i++)
    {
        auto it = find(vcopy.begin(), vcopy.end(), nums1[i]);
        if (it != vcopy.end())
        {
            vcopy.erase(it);
        }
    }
    ans.push_back(vcopy);

    // Remove elements from v that are also present in nums1
    vcopy = v;
    for (int i = 0; i < nums2.size(); i++)
    {
        auto it = find(vcopy.begin(), vcopy.end(), nums2[i]);
        if (it != vcopy.end())
        {
            vcopy.erase(it);
        }
    }
    ans.push_back(vcopy);

    return ans;
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
    vector<int> num2(m); // Corrected to size m
    for (int i = 0; i < m; i++)
    {
        cin >> num2[i];
    }

    vector<vector<int>> ans = findDifference(num1, num2);

    for (auto sv : ans)
    {
        for (auto v : sv)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
