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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())//if either of the arrays are empty, we return null
            return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);//root will always be first element in preorder array.
        int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();//find index of that element in inorder array i.e root element.
        vector<int> lpre(preorder.begin() + 1, preorder.begin() + 1 + mid);//the left subtree's preorder will be the first n elements after first element of original preorder array where n is index of root in inorder array.
        vector<int> rpre(preorder.begin() + 1 + mid, preorder.end());//and the right subtree's preorder will be the remaining elements. (so the preorder array has been split into 2 by skipping the first element).
        vector<int> lin(inorder.begin(), inorder.begin() + mid);//the left subtree's inorder will be all the elements to the left of root in the inorder array.
        vector<int> rin(inorder.begin() + mid + 1, inorder.end());//and the right subtree's inorder will be all the elements to the right of root in the inorder array. (so the inorder array has been split into 2 by skipping the root element).

        root->left = buildTree(lpre, lin);//generate left and right subtree using recursion and the new preorder and inorder arrays.
        root->right = buildTree(rpre, rin);
        return root;//return the root element after attaching the left and right subtrees.
    }
};
