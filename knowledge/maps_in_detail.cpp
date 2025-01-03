#include <bits/stdc++.h>

using namespace std;

void print_m(map<int, string> &m)
{
    for (auto &&i : m) // insertion and access time complexity log(n)
    {
        cout << i.first << " " << i.second << endl;
    }
}
void print_ms(map<string, string> &m)
{
    for (auto &&i : m) // insertion and access time complexity log(n)
    {
        cout << i.first << " " << i.second << endl;
    }
}

bool compareSecond(const pair<int, string> &a, const pair<int, string> &b)
{
    return a.second < b.second;
}

int main()
{
    // normal map , unordered map, multimaps, red black trees
    // map is pair key and value , map is not contineus data structure

    // map<int, string> m;
    // m[1] = "one";
    // m[2] = "two";
    // m.insert({5, "ansh"});

    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     string y;
    //     cin >> x >> y;
    //     m.insert({x, y});
    // }

    // below loop consume more space
    // for (int i = 0; i < m.size(); i++)
    // {
    //     cout << m[i] << endl;
    // }

    // map<int, string>::iterator it;
    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << (*it).first << " " << (*it).second << endl;
    // }
    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    // print_m(m);
    // cout << endl;
    // m[9] = "rohan"; // insert value in map with O(log(n))
    // m[-1];          // insert value in map with O(log(n))
    // print_m(m);
    // cout << endl;

    // for map sorting convert map into vector pair and then sort
    // vector<pair<int, string>> v_p(m.begin(), m.end());

    // sort(v_p.begin(), v_p.end(), compareSecond);

    // for (const auto &p : v_p)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
    // cout << endl;

    // auto it = m.find(70); // this find  function also takes O(log(n)) time  // if not exist so return end() iterator which are empty

    // if (it == m.end())
    // {
    //     cout << "NO VALUE" << endl;
    // }
    // else
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    // cout << endl;
    // m.erase(7); // take input key or iterator

    // auto it1 = m.find(100);
    // if (it1 != m.end()) // this condition are nessecerry
    // {
    //     m.erase(it1); // take input key or iterator
    // }

    // print_m(m);
    // cout << endl;

    // cout << "this is before clear" << endl;
    // m.clear();
    // print_m(m);
    // cout << "this is after clear" << endl;

    // unorderedmap not use pair

    map<string, string> ms;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        ms.insert({x, y}); // in this time we use string as a key so time complexity is O(log(n)*string_size)
    }

    print_ms(ms);


    return 0;
}