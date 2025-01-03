#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head)
{
    if (!head || !head->next)
        return;

    vector<int> s;
    auto curr = head;
    while (curr)
    {
        s.push_back(curr->val);
        curr = curr->next;
    }

    int size = s.size();
    vector<int> ans(size);
    int start = 0;
    int end = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            ans[i] = s[start++];
        }
        else
        {
            ans[i] = s[end--];
        }
    }

    // Update the original list with the reordered elements
    curr = head;
    for (int i = 0; i < size; i++)
    {
        curr->val = ans[i];
        curr = curr->next;
    }
}

int main()
{
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    reorderList(head);

    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
