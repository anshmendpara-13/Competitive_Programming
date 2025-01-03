#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// we also use class insted of struct
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

int main()
{
    vector<int> arr = {25, 5, 6, 7, 3};
    Node *y = new Node(arr[1], nullptr);

    cout << y << endl;
    cout << y->data << endl;
    cout << y->next << endl;

    return 0;
}