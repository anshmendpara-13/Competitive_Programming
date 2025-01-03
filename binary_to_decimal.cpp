#include <iostream>
#include <string>

using namespace std;

int binaryToDecimal(string s)
{
    int decimal = 0;
    int power = s.length() - 1;

    for (char digit : s)
    {
        if (digit == '1')
        {
            decimal += (1 << power);
        }
        power--;
    }

    return decimal;
}

int main()
{
    string s;
    cin >> s;

    int decimalValue = binaryToDecimal(s);
    cout << decimalValue << endl;

    return 0;
}
