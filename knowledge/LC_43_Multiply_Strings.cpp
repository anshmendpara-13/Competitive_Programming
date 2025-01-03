#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// string multiply(string num1, string num2)
// {
//     long long n1 = num1.size();
//     long long n2 = num2.size();
//     string result(n1 + n2, '0');
//     // cout << result << endl;

//     for (long long i = n1 - 1; i >= 0; i--)
//     {
//         for (long long j = n2 - 1; j >= 0; j--)
//         {
//             long long mul = (num1[i] - '0') * (num2[j] - '0');
//             long long sum = mul + (result[i + j + 1] - '0');

//             cout << mul << " " << sum << endl;

//             result[i + j + 1] = (sum % 10) + '0';
//             result[i + j] += sum / 10;
//         }
//     }

//     size_t startPos = result.find_first_not_of('0');
//     if (startPos != string::npos)
//     {
//         return result.substr(startPos);
//     }
//     return "0";
// }

// string add(string num1, string num2)
// {
//     string result;
//     long long carry = 0;
//     long long len1 = num1.size();
//     long long len2 = num2.size();
//     long long i = len1 - 1;
//     long long j = len2 - 1;

//     while (i >= 0 || j >= 0 || carry)
//     {
//         long long digit1 = (i >= 0) ? (num1[i--] - '0') : 0;
//         long long digit2 = (j >= 0) ? (num2[j--] - '0') : 0;
//         long long sum = digit1 + digit2 + carry;
//         result = char(sum % 10 + '0') + result;
//         carry = sum / 10;
//     }

//     return result;
// }

// string multiply(string num1, string num2)
// {
//     if (num1 == "0" || num2 == "0")
//         return "0";

//     string result = "0";
//     long long len1 = num1.size();
//     long long len2 = num2.size();

//     for (long long i = len2 - 1; i >= 0; i--)
//     {
//         string temp;
//         long long carry = 0;

//         long long digit2 = num2[i] - '0';
//         for (long long j = len1 - 1; j >= 0; j--)
//         {
//             long long digit1 = num1[j] - '0';
//             long long product = digit1 * digit2 + carry;
//             temp = char(product % 10 + '0') + temp;
//             carry = product / 10;
//         }

//         if (carry > 0)
//         {
//             temp = char(carry + '0') + temp;
//         }

//         temp += string(len2 - i - 1, '0');
//         result = add(result, temp);
//     }

//     return result;
// }

long long multi(string s, char c)
{
    long long carry = 0;
    long long ans = 0;
    long long subans = 0;
    long long base = 1;
    for (long long i = s.length() - 1; i >= 0; i--)
    {
        long long x = (s[i] - '0') * (c - '0') + carry;
        subans = x % 10;
        carry = x / 10;
        ans += subans * base;
        base *= 10;
    }
    return ans + (carry * base); // Add carry for the most significant digit
}

string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    vector<long long> v(max(num1.length(), num2.length()));

    if (num1.length() > num2.length())
    {
        swap(num1, num2);
    }

    for (long long i = 0; i < num2.length(); i++)
    {
        long long x = multi(num1, num2[i]);
        v.push_back(x);
    }

    reverse(v.begin(), v.end());
    long long base = 1;
    long long ans = 0;
    for (auto val : v)
    {
        ans += (val * base);
        base *= 10;
    }
    return to_string(ans);
}

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    string ans = multiply(s1, s2);
    cout << ans << endl;
    return 0;
}