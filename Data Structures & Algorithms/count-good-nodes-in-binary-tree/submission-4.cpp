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
    int goodNodes(TreeNode* root) 
    {
        int res = 0;
        queue<pair<TreeNode*, int>> q; //this will store the node and the highest value in its ancestors
        q.push({root, INT_MIN});
        while(!q.empty())
        {
            TreeNode* temp = q.front().first;
            int highestval = q.front().second;
            q.pop();
            if (temp->val >= highestval)
                res++; //increase res if the value is higher than the highest val of ancestors

            highestval = max(temp->val, highestval); //update highestval
            
            if (temp->left) //push left and right (if they exist) with the updated highestval
                q.push({temp->left, highestval});
            if (temp->right)
                q.push({temp->right, highestval});
        }
        return res;  
    }
};
