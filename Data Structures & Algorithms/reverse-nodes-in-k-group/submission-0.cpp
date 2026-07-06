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
private:
        ListNode* getkth(ListNode* curr, int k) 
        {
            while (curr && k > 0) 
            {
                curr = curr->next;
                k--;
            }
        return curr;
        }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* grpprev= new ListNode(0,head); //initial group's prev i.e. 0th node
        ListNode* zeroth = grpprev;
        while(true)
        {
            ListNode* kth = getkth(grpprev, k); //get kth node
            if (!kth) // if kth is nullptr then break this loop as we dont need to reverse this group
                break;
            ListNode* grpnext = kth->next; //group's next is kth next
            
            ListNode* prev = kth->next; // from here we reverse the group
            ListNode* curr = grpprev->next;
            while (curr != grpnext)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            
            ListNode* tmp = grpprev->next; //set temp to last node (first before reversing)
            grpprev->next = kth; //make sure grpprev points to the new first node i.e. kth node
            grpprev = tmp; //set grpprev to temp
        }
        return zeroth->next;
        
    }
};
