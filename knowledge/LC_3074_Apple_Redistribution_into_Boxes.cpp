#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int possible(vector<int> apple, vector<int> capacity)
{
    int acc = accumulate(apple.begin(), apple.end(), 0);
    std::sort(capacity.begin(), capacity.end(), [](int a, int b)
              { return a > b; });

    int ans = 0;
    int i = 0;

    for (int i = 0; i < capacity.size(); i++)
    {
        if (acc > 0)
        {
            if (capacity[i] > 0)
            {
                acc -= capacity[i];
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> n1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> n1[i];
    }
    int m;
    cin >> m;
    vector<int> n2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> n2[i];
    }

    int ans = possible(n1, n2);
    cout << ans << endl;

    return 0;
}