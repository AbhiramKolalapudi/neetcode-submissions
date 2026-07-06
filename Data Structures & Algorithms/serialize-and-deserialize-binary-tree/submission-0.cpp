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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serial_dfs(root, s);//add elements to string s from root
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ','); //converts string to array of elements where each element is a string
        int i = 0; //create global variable i as index for the array
        return deserial_dfs(vals, i); //return the root node
    }

private:
    void serial_dfs(TreeNode*root, string& s)
    {
        //we use preorder method (root, left, right) to store the elements in a string
        if(!root)
        {
            s = s + "N,";//if null then add N to string
            return;
        }
        s = s + to_string(root->val) + "," ;//else add the val to string
        serial_dfs(root->left, s);
        serial_dfs(root->right, s);
    }

    vector<string> split(const string &s, char delim) 
    {
        //this fn is used to split the string into an array by using ',' as delimiter.
        vector<string> elems;//output vector
        stringstream ss(s);//read string one by one as a stream
        string item;
        while (getline(ss, item, delim))//reads from ss and stores result in item unless its delim.
        {
            elems.push_back(item);//add item to vector
        }
        return elems;
    }

    TreeNode* deserial_dfs(vector<string>& vals, int& i)
    {
        //we use preorder method to convert the string array to a valid binary tree
        if(vals[i]=="N")//if we see N, we return nullptr
        {
            i++;//increment the global variable i
            return nullptr;
        }
        TreeNode* newnode = new TreeNode(stoi(vals[i]));//else we create new node with the value i.e. array element but its a string so we convert to int
        i++;//increment the global variable i
        newnode->left = deserial_dfs(vals, i);//as its preorder it will be root, left, right
        newnode->right = deserial_dfs(vals, i);
        return newnode; //return the top root node
    }
};
