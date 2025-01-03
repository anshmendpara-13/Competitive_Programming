#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        long long f;

        cin >> n >> k >> f;
        vector<pair<int, int>> prs;
        for (int i = 0; i < n; i++)
        {
            int dist, food;
            cin >> dist >> food;
            prs.push_back({k - dist, food});
        }

        int ans = 0;
        multiset<int> food_avl; // o(1) to find max, min value
        sort(prs.begin(), prs.end());
        bool can_reach = true;
        int cur = 0;

        for (int i = 1; i < k; i++)
        {
            f--;
            if (prs[cur].first == i)
            {
                food_avl.insert(prs[cur].second);
                cur++;
            }
            if (f == 0)
            {
                if (food_avl.size() == 0)
                {
                    can_reach = false;
                    break;
                }
                else
                {
                    auto it = --food_avl.end(); // last element in the set
                    f += (*it);                 // add food
                    food_avl.erase(it);         // erase single element from set // o(1) for erase in using iterator // o(log(n)) for erase in using pass value
                    ans++;
                }
            }
        }

        if (can_reach)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}