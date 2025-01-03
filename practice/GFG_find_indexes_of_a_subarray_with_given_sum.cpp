#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> subarraySum(vector<int> arr, int n, long long s)
{
    int sum = 0;
    vector<int> ans;
    int j = 0;
    int i = 0;
    while (i < arr.size())
    {
        sum += arr[i];
        while (j < i && sum > s)
        {
            sum -= arr[j];
            j++;
        }

        if (sum == s)
        {
            ans.push_back(j + 1);
            ans.push_back(i + 1);
            return ans;
        }
        i++;
    }
    ans.push_back(-1);
    return ans;
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
    long long s;
    cin >> s;

    vector<int> result = subarraySum(arr, n, s);
    for (auto val : result)
    {
        cout << val << " ";
    }

    return 0;
}