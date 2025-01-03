#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> evenOddBit(int n)
{
    vector<int> ans;
    int even_one = 0;
    int odd_one = 0;
   

    for (int i = 0; i < log2(n) + 1; i++)
    {
        if (i % 2 == 0 && (n & (1 << i)))
            even_one++;
        else if (i % 2 != 0 && (n & (1 << i)))
            odd_one++;
    }

    ans.push_back(even_one);
    ans.push_back(odd_one);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    ans = evenOddBit(n);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}