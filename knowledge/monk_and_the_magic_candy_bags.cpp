#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int bags, min;
        cin >> bags >> min;

        multiset<int> s;

        for (int i = 0; i < bags; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }

        int total = 0;

        for (int i = 0; i < min; i++)
        {
            auto last_it = s.end();
            last_it--;
            int candy_ct = *last_it;
            total += candy_ct;
            s.erase(last_it);
            s.insert((candy_ct) / 2);
        }

        cout << total << endl;
    }

    return 0;
}