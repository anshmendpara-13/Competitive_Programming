#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int leastInterval(vector<char> &tasks, int n)
{
    int freq[26] = {0};
    for (char task : tasks)
    {
        freq[task - 'A']++;
    }

    sort(begin(freq), end(freq));

    int chunk = freq[25] - 1;
    int idle = chunk * n;

    for (int i = 0; i < 25; i++)
    { // Loop in ascending order
        idle -= min(chunk, freq[i]);
    }

    int ans = idle < 0 ? tasks.size() : tasks.size() + idle;
    return ans;
}

int main()
{
    int n, y;
    cin >> n >> y;
    vector<char> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = leastInterval(v, y);
    cout << ans << endl;

    return 0;
}