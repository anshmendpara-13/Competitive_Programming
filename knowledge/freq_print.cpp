// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     unordered_map<string, int> m;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         string s;
//         cin >> s;
//         m[s]++;
//     }

//     int q;
//     cin >> q;

//     while (q--)
//     {
//         string in;
//         cin >> in;
//         cout << m[in] << endl;
//     }

//     auto maxFreqElement = max_element(m.begin(), m.end(), [](const auto &a, const auto &b)
//                                       { return a.second < b.second; });

//     cout << "Key with maximum frequency: " << maxFreqElement->first << " (Frequency: " << maxFreqElement->second << ")" << endl;

//     return 0;

// }

#include <bits/stdc++.h>

using namespace std;

int main()
{
    multimap<string, int> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m.insert({s, 1}); // Inserting with value 1, as you are counting occurrences
    }

    int q;
    cin >> q;

    while (q--)
    {
        string in;
        cin >> in;
        cout << m.count(in) << endl;
    }

    cout << endl;

    // Find the key(s) with maximum frequency
    int maxFrequency = 0;
    vector<string> maxFreqKeys;

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        int currentFrequency = m.count(it->first);
        if (currentFrequency > maxFrequency)
        {
            maxFrequency = currentFrequency;
            maxFreqKeys = {it->first};
        }
        else if (currentFrequency == maxFrequency)
        {
            maxFreqKeys.push_back(it->first);
        }
    }

    // Output keys with maximum frequency
    cout << "Keys with maximum frequency (" << maxFrequency << "): ";
    for (const auto &key : maxFreqKeys)
    {
        cout << key << " ";
    }
    cout << endl;

    return 0;
}
