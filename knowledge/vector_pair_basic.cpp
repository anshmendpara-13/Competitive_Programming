#include <bits/stdc++.h>

using namespace std;

// void print_vec(vector<int> v)
void print_vec(vector<int> &v) // reference
{

    // v.size() -> O(1)

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    // pair<int, string> p;
    // p = make_pair(2,"abc");

    // pairX<int, string> p1;
    // p1 = {5,"555"};
    // cout << "The integer is: " << p1.first << endl;
    // cout << "The string is: " << p1.second << endl;

    // pair<int, int> p_array[3];
    // p_array[0] = {1, 2};
    // p_array[1] = {2, 3};
    // p_array[2] = {3, 4};
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << p_array[i].first << " " << p_array[i].second << endl;
    // }

    // vector<int> v; // initial size is zero

    // int n;
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     v.push_back(x); // O(1)
    // }
    // print_vec(v);

    vector<int> v(7, 2); // initial size and all elements are the same value
    v.push_back(7);
    v.push_back(89);
    print_vec(v);
    cout << endl;
    v.pop_back(); // remove the last value
    print_vec(v);
    cout << endl;

    // vector<int> v2 = v;  // copy vector into v2 not reference  // time coplexity O(n)
    vector<int> &v2 = v; // copy vecotr with reference  // time coplexity O(n)
    v2.pop_back();
    v2.push_back(89);
    print_vec(v2);
    cout << endl;
    v2.push_back(13);

    return 0;
}