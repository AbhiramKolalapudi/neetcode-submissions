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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //normal BFS traversal -> first push root into queue, then from here pop one element (visit it) and push its left and right into queue,
        // and repeat until queue is empty
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int levelsize = q.size();//number of elements in that level
            vector <int> level;//all elements in that level
            for (int i=0; i<levelsize; i++)
            {
                TreeNode* node = q.front();// pop front element and push its left and right into queue if they exist 
                q.pop();
                level.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            res.push_back(level);//push level and again reset it for next level
        }
        return res;
    }
};
