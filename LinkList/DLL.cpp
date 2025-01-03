#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};

Node *convertarray2dll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *deletehead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node *deletetail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *pre = tail->back;
    tail->back = nullptr;
    pre->next = nullptr;
    delete tail;
    return head;
}

Node *removekthelement(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    int cnt = 1;
    Node *kthnode = head;
    while (kthnode != nullptr && cnt < k)
    {
        cnt++;
        kthnode = kthnode->next;
    }

    if (kthnode == nullptr)
    {
        return head;
    }

    if (kthnode->back == nullptr)
    {
        head = deletehead(head);
    }
    else if (kthnode->next == nullptr)
    {
        head = deletetail(head);
    }
    else
    {
        kthnode->back->next = kthnode->next;
        kthnode->next->back = kthnode->back;
        delete kthnode;
    }
    return head;
}

void deletenode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    delete temp;
}

Node *insertbeforehead(Node *head, int val)
{
    Node *newhead = new Node(val, head, nullptr);
    head->back = newhead;
    return newhead;
}

Node *insertbeforetail(Node *head, int val)
{
    if (head->next == nullptr)
        return insertbeforehead(head, val);
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *newnode = new Node(val, tail, prev);
    prev->next = newnode;
    tail->back = newnode;
    return head;
}

Node *insertbeforekthelement(Node *head, int k, int val)
{
    if (k == 1)
        return insertbeforehead(head, val);
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newnode = new Node(val, temp, prev);
    prev->next = newnode;
    temp->back = newnode;

    return head;
}

void insertbeforenode(Node *node, int val)
{
    Node *prev = node->back;
    Node *newnode = new Node(val, node, prev);
    prev->next = node;
    node->back = newnode;
}

int main()
{
    vector<int> arr = {12, 5, 6, 9, 87};
    Node *head = convertarray2dll(arr);
    print(head);
    head = deletehead(head);
    print(head);
    head = deletetail(head);
    print(head);
    head = removekthelement(head, 3);
    print(head);
    head = insertbeforehead(head, 89);
    print(head);
    head = insertbeforetail(head, 123);
    print(head);
    head = insertbeforekthelement(head, 2, 55);
    print(head);

    return 0;
}
