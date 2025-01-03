#include <bits/stdc++.h>

using namespace std;

int digit_sum(int val)
{
    int sub_sum_of_digit = 0;
    while (val > 0)
    {
        int last_digit = val % 10;
        sub_sum_of_digit = sub_sum_of_digit + last_digit;
        val = val / 10;
    }
    return sub_sum_of_digit;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum_of_digit = 0;

    // below code for perticular only
    // while (n > 0)
    // {
    //     int last_digit = n % 10;
    //     sum_of_digit = sum_of_digit + last_digit;
    //     n = n / 10;
    // }
    // cout << sum_of_digit << endl;

    for (int i = 0; i < n; i++)
    {
        int val = digit_sum(arr[i]);
        sum_of_digit += val;
    }

    cout << sum_of_digit << endl;

    return 0;
}