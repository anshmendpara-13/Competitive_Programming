#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void printBinary(int num)
{
    for (int i = log2(num); i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

void printBinary_with_size(int num, int size)
{
    for (int i = size; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    printBinary(n);

    int i = 3;
    if ((n & (1 << i)) != 0)
    {
        cout << "set bit" << endl;
    }
    else
    {
        cout << "unset bit" << endl;
    }

    // set bit using or operation ex.. below example we set third bit
    n = n | (1 << 2); // 1001 | 0100 = 1101
    printBinary(n);

    // unset particular bit using xor operation
    n = n ^ (1 << 0); // 1101 ^ 0001 = 1100
    printBinary(n);

    // print inverse binary or.. toggle all bits
    int a = 8;
    int size = log2(a); // Size of the integer in bits
    printBinary_with_size(~a, size);

    // or.. of unset the set bit
    a = 7;
    printBinary_with_size(a & (~(1 << 1)), size);

    int b = 64;
    printBinary(b);
    printBinary_with_size(b, log2(b));
    int set_bit_cnt = 0;
    for (int i = 0; i <= ceil(log2(b)); i++)
    {
        if ((b & (1 << i)) != 0)
        {
            set_bit_cnt++;
        }
    }
    cout << "total set bits : " << set_bit_cnt << endl;
    cout << "total unset bits : " << ceil(log2(b)) - set_bit_cnt << endl;

    // Shortcuts *******************************
    cout << "Shortcuts outputs" << endl;
    a = 8;
    printBinary(a);

    // this all work on 32 bits
    cout << __builtin_popcount(a) << endl;
    cout << __builtin_popcountll(1LL << 35) << endl;
    cout << __builtin_clz(a) << endl;
    cout << __builtin_ctz(a) << endl;

    // direct binary to integer
    cout << "binary to integer" << endl;
    auto number = 0b1001;
    cout << number << endl;



    return 0;
}