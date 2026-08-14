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
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        bool empty = dfs(root, target);
        if (empty)
            return NULL;
            
        return root;
    }

private:
    bool dfs (TreeNode* node, int target)
    {
        if (node == NULL)
            return true;
        
        bool left = dfs(node->left, target);
        bool right = dfs(node->right, target);

        if (left)
            node->left = NULL;

        if (right)
            node->right = NULL;
        
        if (left && right && node->val == target)

            return true;

        return false;

    }
};