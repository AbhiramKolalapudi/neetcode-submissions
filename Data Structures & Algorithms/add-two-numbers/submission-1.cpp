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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* res = new ListNode(0);
        ListNode*tempres = res;
        int sum = 0;
        int carry = 0;
        while (temp1 || temp2)
        {
            if (!temp1)
                sum = temp2->val + carry;
            else if (!temp2)
                sum = temp1->val + carry;
            else
                sum = temp1->val + temp2->val + carry;
                carry = sum/10;
                sum = sum%10;
            ListNode* node = new ListNode(sum);
            tempres->next = node;
            tempres = tempres->next;
            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }
        if (carry)
            tempres->next = new ListNode(carry);
        res = res->next;
        return res;
    }
};
