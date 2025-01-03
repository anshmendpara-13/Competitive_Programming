#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min = *min_element(arr.begin(), arr.end());
    cout << min << endl;

    int acc = accumulate(arr.begin(), arr.end(), 0);
    cout << acc << endl;

    int ct = count(arr.begin(), arr.end(), min);
    cout << ct << endl;

    auto element = find(arr.begin(), arr.end(), 89);
    if (element != arr.end())
    {
        cout << *element << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    reverse(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s << endl;

    // cout << [](int x, int y)
    // { return x + y; }(2,6)
    //      << endl;

    auto sum = [](int x, int y)
    { return x * y; };
    cout << sum(5, 6) << endl;

    cout << all_of(arr.begin(), arr.end(), [](int x)
                   { return x > 0 ? 1 : 0; }) // ek negative to zero
         << endl;

    cout << any_of(arr.begin(), arr.end(), [](int x)
                   { return x > 0 ? 1 : 0; }) // badha negative to zero
         << endl;

    cout << none_of(arr.begin(), arr.end(), [](int x)
                    { return x > 0 ? 1 : 0; }) // badha negative to one
         << endl;

    return 0;
}