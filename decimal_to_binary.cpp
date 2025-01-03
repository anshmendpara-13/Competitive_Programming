#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void decToBinary(int n)
{
    float x = ceil(log2(n));
    cout << x << endl;
    for (int i = x; i >= 0; i--)
    {
        int k = n >> i;
        // cout << n << endl;
        // cout << i << endl;
        // cout << k << endl;
        // cout << endl;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}

void decimalToBinary(int n)
{
    bitset<32> binaryRepresentation(n);
    cout << binaryRepresentation << endl;
}

int main()
{
    int n;
    cin >> n;
    decToBinary(n);
    decimalToBinary(n);
}
