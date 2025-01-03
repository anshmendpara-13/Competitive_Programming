// #include <bits/stdc++.h>

// using namespace std;

// // void print_vec(vector<pair<int, int>> &v)
// // {
// //     for (int i = 0; i < v.size(); ++i)
// //     {
// //         cout << v[i].first << "," << v[i].second << endl;
// //     }
// // }

// void print_vec(vector<int> &v)
// {
//     for (int i = 0; i < v.size(); ++i)
//     {
//         cout << v[i] << " ";
//     }
// }

// int main()
// {
//     // vector<pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}};
//     // print_vec(v);

//     // int n;
//     // cin >> n;
//     // vector<pair<int, int>> v;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     int x, y;
//     //     cin >> x >> y;
//     //     // v.push_back({x, y});
//     //     v.push_back(make_pair(x, y));
//     // }
//     // print_vec(v);

//     // int n;
//     // cin >> n;
//     // vector<int> v[n];

//     // for (int i = 0; i < n; i++)
//     // {
//     //     int size;
//     //     cin >> size;
//     //     for (int j = 0; j < size; j++)
//     //     {
//     //         int x;
//     //         cin >> x;
//     //         v[i].push_back(x);
//     //     }
//     // }

//     // for (int i = 0; i < n; i++)
//     // {
//     //     print_vec(v[i]);
//     //     cout << endl;
//     // }

//     // cout << v[1][1] << endl;

//     int n;
//     cin >> n;
//     vector<vector<int>> v;

//     for (int i = 0; i < n; i++)
//     {
//         int size;
//         cin >> size;

//         vector<int> temp;

//         for (int j = 0; j < size; j++)
//         {
//             int x;
//             cin >> x;
//             temp.push_back(x);
//         }

//         v.push_back(temp);

//         // v.push_back(vector<int>());

//         // for (int j = 0; j < size; j++)
//         // {
//         //     int x;
//         //     cin >> x;
//         //     v[i].push_back(x);
//         // }
//     }

//     for (int i = 0; i < v.size(); i++)
//     {
//         print_vec(v[i]);
//         cout << endl;
//     }

//     v[0].push_back(7);              // in this case , we are adding an element to the first row of the vector
//     v.push_back(vector<int>(5, 1)); // push back empty vector

//     for (int i = 0; i < v.size(); i++)
//     {
//         print_vec(v[i]);
//         cout << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Input
    int xSize, ySize, zSize;

    cout << "Enter the size of the 3D vector (x y z): ";
    cin >> xSize >> ySize >> zSize;

    vector<vector<vector<int>>> v;

    v.resize(xSize, vector<vector<int>>(ySize, vector<int>(zSize)));

    cout << "Enter elements of the 3D vector:\n";
    for (int x = 0; x < xSize; ++x)
    {
        for (int y = 0; y < ySize; ++y)
        {
            for (int z = 0; z < zSize; ++z)
            {
                cout << "v[" << x << "][" << y << "][" << z << "]: ";
                cin >> v[x][y][z];
            }
        }
    }

    // Output
    cout << "The 3D vector elements are:\n";
    for (int x = 0; x < xSize; ++x)
    {
        for (int y = 0; y < ySize; ++y)
        {
            for (int z = 0; z < zSize; ++z)
            {
                cout << v[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
