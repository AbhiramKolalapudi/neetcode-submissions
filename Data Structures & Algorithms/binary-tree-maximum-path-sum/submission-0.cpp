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
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode*root, int& res)//helper function that can update original res
    {
        //the return value is always the non split value from root i.e. we dont consider both left and right subtrees, we only consider max of them.
        //but the split value is computed and if its more than current res then res is updates to the split value.
        //(the split value is the value we get by splitting at root by taking both left and right, and not considering its parent)
        if (!root)//return 0 if null
            return 0;

        int leftmax = dfs(root->left, res);//computing the max value we can get without spliting the left element.
        int rightmax = dfs(root->right, res);// computing the max value we can get without splitting the right element.
        leftmax = max(leftmax, 0);//if its negative then replace it by 0 i.e. we dont include that subtree itself in calculation of res or returning non split value
        rightmax = max(rightmax,0);
        
        res = max(res, root->val + leftmax + rightmax);//we consider splitting at root and then compute the total and see if its bigger than res 

        return (root->val + max(leftmax, rightmax));//return the non split value from root
    }
};
