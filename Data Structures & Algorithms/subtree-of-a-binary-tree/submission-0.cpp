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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)//subroot empty -> true (base case)
            return true;
        if (!root)//root empty but subroot not empty -> not true (base case)
            return false;
        if(isSameTree(root, subRoot))//root and subroot are same if not now, atleast in a recursive call -> true
            return true;

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)); //if none of the above then we check is subroot is match either left or right root (recursive case)

    }
    bool isSameTree(TreeNode* p, TreeNode* q) //exact function from last qn
    {
        if (!p && !q)
            return true;
        
        if (p && q && p->val == q->val)
        {
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
        else
            return false;
    }
};
