/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* revhead = nullptr;
        ListNode* realhead = nullptr;
        ListNode* before = nullptr;

        for (int i = 1; i <= right; i++)
        {
            if (i == 1 && left > 1)
                realhead = curr;
            if (i == left)
            {
                revhead = curr;
                before = prev;
            }
            if (i >= left)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        revhead->next = curr;
        if (before != nullptr)
            before->next = prev;
        else
            realhead = prev;
        return realhead;
    }
};