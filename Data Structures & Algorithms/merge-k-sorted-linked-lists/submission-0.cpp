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
    //we can do the normal solution like we did for 2 sorted ll
    //but that will be O(n*k) time.
    //instead we do divide and conquer method where we first 
    //combine 2 ll and half the total number of ll and repeat
    //until one is left at the end, and this method will be 
    //O(n*logk) time as we need to perform merging 2 sorted ll
    //a total of (log k) times.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        while(lists.size() > 1) //repeat until one element(ll) is left
        {
            vector<ListNode*> mergedlists; //add all merged ll, hence for every iteration the total elements will be halved 
            for(int i=0; i < lists.size(); i+=2) //get lists[i] and lists[i+1] and merge them
            {
                if ((i+1) < lists.size())
                {
                    ListNode* merged = mergeTwoLists(lists[i], lists[i+1]);
                    mergedlists.push_back(merged);
                }
                else //total ll are odd, hence we directly push the last element
                    mergedlists.push_back(lists[i]);
            }
            lists = mergedlists; //update origial lists with merged
        }
        return lists[0]; //final merged ll will be first element in the lists vector

    }

    //this is the exact function from merge 2 sorted ll solution
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode* temp = &head;
        while(list1 && list2)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else 
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1)
        {
            temp->next = list1;
        }
        else if(list2)
        {
            temp->next = list2;
        }
        return head.next;
    }
};
