#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    set<int> ans;
    vector<int> final_ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                ans.insert(nums1[i]);
            }
        }
    }

    for (auto val : ans)
    {
        final_ans.push_back(val);
    }

    return final_ans;
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

    vector<int> ans = intersection(num1, num2);
    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}