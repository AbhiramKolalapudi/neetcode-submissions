/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
//we need inorder traversal as that will give ascending order elements of bst
//we can do either recursive approach and add all elements to array and find kth element but for that we go throught entire bst.
//or we can do recursive and manage a counter to find kth element but that would need global variables.
//so we do iterative approach and manage a counter and once it hits 0, we return the element.
        stack <TreeNode*> st;
        TreeNode* curr = root;
        while(curr != nullptr || !st.empty()) //goes on until curr is null and st is empty
        {
            while(curr != nullptr)//push element to st and go left until null 
            {
                st.push(curr);
                curr=curr->left;
            }
            curr = st.top();//set curr to top and pop that element from st
            st.pop();
            k--;//reduce counter
            if(k == 0)//if counter is 0, return curr->val
                return curr->val;
            curr = curr->right;//if not then go to its right and repeat
        }
        return -1;
    }
};
