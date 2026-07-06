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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (p->val <= root->val && q->val >= root->val) //p and q are in different sides of root hence return root (base case)
            return root; 
        if (p->val >= root->val && q->val <= root->val)
            return root;
        if (p->val > root->val) //p and q are on same side of root hence we run the function again on that side (recursive case)
            return lowestCommonAncestor(root->right, p, q);
        if (p->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
    }
};
