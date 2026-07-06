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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy; //extra node before the head
        dummy.next = head;
        ListNode* right = &dummy;
        ListNode* left = &dummy;
        for (int i = 0; i < n; i++)//move r by n
        {
            right = right->next;
        }
        while(right->next)//move r and l by same distance until r is at end
        {
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;//remove left->next
        return dummy.next;//return dummy.next instead of head because head also might be deleted
    }
};
