#include <bits/stdc++.h>

using namespace std;

// void print_m(multimap<string, int> &m)
// {

//     for (auto &&i : m)
//     {
//         cout << i.first << " " << i.second << endl;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     multimap<string, int> m;

//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         string str;
//         cin >> str >> x;
//         m.insert({str, x});
//     }

//     // to sort the map first strore values in vector and then sort
//     vector<pair<string, int>> sortedByValues(m.begin(), m.end());
//     sort(sortedByValues.begin(), sortedByValues.end(), [](const auto &a, const auto &b)
//          { return a.second > b.second; });

//     for (const auto &pair : sortedByValues)
//     {
//         cout << pair.first << " " << pair.second << endl;
//     }

//     // print_m(m);

//     // cout <<  <<endl;
//     return 0;
// }

// ***************************************************** Method 1

// int main()
// {

//     map<int, multiset<string>> marks_map;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int marks;
//         string name;
//         cin >> name >> marks;
//         marks_map[marks].insert(name);
//     }

//     auto cur_it = marks_map.end();
//     cur_it--;

//     while (true)
//     {
//         auto students = (*cur_it).second;
//         int marks = (*cur_it).first;

//         for (auto &&i : students)
//         {
//             cout << i << " " << marks << endl;
//         }

//         if (cur_it == marks_map.begin())
//         {
//             break;
//         }
//         cur_it--;
//     }
// }

// ***************************************************** Method 2

int main()
{

    map<int, multiset<string>> marks_map; // store in ascending order
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int marks;
        string name;
        cin >> name >> marks;
        marks_map[-1 * marks].insert(name);
    }

    for (auto &&marks_students : marks_map)
    {
        auto &students = marks_students.second;
        int makrs = marks_students.first;

        for (auto &&student : students)
        {
            cout << student << " " << -1 * makrs << endl;
        }
    }
}

// ***************************************************** Method 3