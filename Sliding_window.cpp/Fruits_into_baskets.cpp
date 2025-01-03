#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int func(vector<int> &arr, int size_of_bucket) // O(n^2)
{
    int maxlen = 0;
    set<int> st; // S(n)

    for (int i = 0; i < arr.size(); i++)
    {
        st.clear();
        for (int j = i; j < arr.size(); j++)
        {
            st.insert(arr[j]); // O(log n)
            if (st.size() <= size_of_bucket)
                maxlen = max(maxlen, j - i + 1);
            else
                break;
        }
    }
    return maxlen;
}

int func1(vector<int> &arr, int size_of_bucket) // O(n)
{
    int l = 0, r = 0, maxlen = 0;
    unordered_map<int, int> mp;

    while (r < arr.size())
    {
        mp[arr[r]]++;
        if (mp.size() > size_of_bucket)
        {

            mp[arr[l]]--;
            if (mp[arr[l]] == 0)
            {
                mp.erase(arr[l]);
            }
            l++;
        }
        if (mp.size() <= size_of_bucket)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int func2(vector<int> &arr, int size_of_bucket) // O(n*2)
{
    int l = 0, r = 0, maxlen = 0;
    unordered_map<int, int> mp;

    while (r < arr.size())
    {
        mp[arr[r]]++;
        if (mp.size() > size_of_bucket)
        {
            while (mp.size() > size_of_bucket)
            {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0)
                {
                    mp.erase(arr[l]);
                }
                l++;
            }
        }
        if (mp.size() <= size_of_bucket)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main()
{

    int n, size_of_bucket;
    cin >> n >> size_of_bucket;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << func(arr, size_of_bucket) << endl;
    cout << func1(arr, size_of_bucket) << endl;
    // cout << func2(arr, size_of_bucket) << endl;

    return 0;
}