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
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        while(!q.empty())
        {
            TreeNode* temp = q.front().first;
            int highestval = q.front().second;
            q.pop();
            if (temp->val >= highestval)
            {
                res++;
                if (temp->left)
                    q.push({temp->left, temp->val});
                if (temp->right)
                    q.push({temp->right, temp->val});
            }
            else
            {
                if (temp->left)
                    q.push({temp->left, highestval});
                if (temp->right)
                    q.push({temp->right, highestval});
            }
        }
        return res;
        
    }
};
