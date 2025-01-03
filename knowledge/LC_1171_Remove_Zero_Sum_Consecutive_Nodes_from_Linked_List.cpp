#include <unordered_map> // this is not done yet!!!!!!!!!!!!!!

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *current = dummy;

    std::unordered_map<int, ListNode *> sumMap;
    int sum = 0;

    while (current != nullptr)
    {
        sum += current->val;

        if (sumMap.find(sum) != sumMap.end())
        {
            // Remove nodes between sumMap[sum] and current
            ListNode *temp = sumMap[sum]->next;
            int tempSum = sum + temp->val;
            while (temp != current)
            {
                sumMap.erase(tempSum);
                ListNode *deleteNode = temp;
                temp = temp->next;
                delete deleteNode;
                tempSum += temp->val;
            }
            sumMap[sum]->next = current->next;
            delete current;
            current = sumMap[sum];
        }
        else
        {
            sumMap[sum] = current;
        }

        current = current->next;
    }

    return dummy->next;
}
