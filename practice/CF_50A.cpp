#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    int size = n * m;
 
    int max_value = max(n, m);
    int min_value = min(n, m);
 
    int total = (max_value * (min_value / 2) + (((min_value % 2) * max_value) / 2));
    cout << total << endl;
 
    return 0;
}