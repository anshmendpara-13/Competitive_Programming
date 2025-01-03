#include <bits/stdc++.h>

using namespace std;

// void print_s(set<string> &s)
// {
//     for (auto &i : s)
//     {
//         cout << i << endl;
//     }

//     // for (auto it = s.begin(); it != s.end(); it++)
//     // {
//     //     cout << *it << endl;
//     // }
// }

void print_s(multiset<string> &s)
{
    for (auto &i : s)
    {
        cout << i << endl;
    }

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << endl;
    // }
}

int main()
{
    // set<string> s;    // in sorted order and unique elements
    // s.insert("ansh"); // log(n) inseriton and access
    // s.insert("fjsl");
    // s.insert("ansh");
    // s.insert("cc");
    // s.insert("ghdkg");
    // s.insert("ldgj");

    // auto it = s.find("ansh");
    // if (it != s.end())
    // {
    //     // cout << (*it) << endl;
    //     s.erase(*it);
    // }

    // print_s(s);

    multiset<string> s; // O(log(n))
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    auto it = s.find("ansh"); // using iterator only one value are deleted
    if (it != s.end())
    {
        s.erase(it); // which are point by iterator
        cout << *it << endl;
    }

    cout << endl;
    print_s(s);

    cout << endl;
    s.erase("ansh"); // delete all the finding values
    print_s(s);

    cout << endl;
    s.clear();

    return 0;
}