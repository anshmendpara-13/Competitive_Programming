#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e2 + 7;
int n;
long long m;
long long trees[N];

bool is_woodSufficient(int h)
{
    long long wood = 0;
    for (int i = 0; i < n; i++)
    {
        if (trees[i] >= h)
        {
            wood += (trees[i] - h);
        }
    }
    return wood >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }

    long long lo = 0, hi = 0; // Initialize hi to 0
    for (int i = 0; i < n; i++)
    {
        hi = max(hi, trees[i]); // Find the maximum tree height
    }

    while (hi - lo > 1)
    {
        long long mid = lo + (hi - lo) / 2;
        if (is_woodSufficient(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }

    // we want max height
    if (is_woodSufficient(hi))
    {
        cout << hi << endl;
    }
    else
    {
        cout << lo << endl;
    }

    return 0;
}
