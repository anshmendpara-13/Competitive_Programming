#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertarrtoll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main()
{

    vector<int> arr = {25, 5, 6, 7, 3};
    Node *head = convertarrtoll(arr);
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }

    return 0;
}