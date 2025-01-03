#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void printBinary(int num)
{
    int size = log2(num);
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     printBinary(i);

    //     if (i & 1) //-->> % and / are slow
    //     {
    //         cout << "odd" << endl;
    //     }
    //     else
    //     {
    //         cout << "even" << endl;
    //     }
    // }

    // cout << "mult and div" << endl;
    // cout << (n >> 1) << endl;
    // cout << (n << 1) << endl;

    // for (char i = 'A'; i <= 'E'; i++)
    // {
    //     cout << i << endl;
    //     cout << char((int(i) | (1 << 5))) << endl;
    //     printBinary((int(i) | (1 << 5)));
    // }
    // for (char i = 'a'; i <= 'e'; i++)
    // {
    //     cout << i << endl;
    //     cout << char((int(i) & (~(1 << 5)))) << endl;
    //     printBinary((int(i) & (~(1 << 5))));
    // }

    // -->> 32 is Ascii of space
    // cout << char(1 << 5) << endl;

    // cout << char('l' & '_') << endl;  // convert  to lowercase to  uppercase
    // cout << char('A' | ' ') << endl;  // convert  to uppercase to lowercase

    printBinary(89);
    int a = 89;
    // // ith bit tak sare lsb ko karana ho to
    // int b = (a & (~((1 << (n + 1)) - 1)));
    // printBinary(b);

    // // ith bit tak sare msb ko karana ho to
    // int c = (a & ((1 << (n + 1)) - 1));
    // printBinary(c);

    if (n & (n - 1))
    {
        cout << "not power of 2" << endl;
    }
    else
    {
        cout << "power of 2" << endl;
    }

    return 0;
}