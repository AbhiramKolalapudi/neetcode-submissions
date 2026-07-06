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
    bool isValidBST(TreeNode* root) {
        return valid(root, INT_MIN, INT_MAX); //another fn with lower and upper limit for root->val
    }

    bool valid(TreeNode* root, int llimit, int ulimit)
    {
        if(!root)//nullptr will return true (base case)
            return true; 
        if(root->val <= llimit || root->val >= ulimit)//if root->val is less than lower limit or more than upper limit then return false (base case)
            return false;
        return (valid(root->left, llimit, root->val) && valid(root->right, root->val, ulimit));//checking if root->left && root->right are valid
        //when we are going left, the lower limit remains same and upper limit changes to root->val as left shouldnt be more than root->val
        //when we are going right, the upper limit remains same and lower limit changes to root->val as right shouldnt be less than root->val
    }
};
