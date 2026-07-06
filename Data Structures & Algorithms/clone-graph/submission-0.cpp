/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldtonew; //maps old nodes with new nodes so that we dont make a multiple copies of the same old node
                                    //so basically the map is (oldtonew[original] = copy)
        return (dfs(node, oldtonew));
    }


private:
    Node* dfs(Node* node, map<Node*, Node*>& oldtonew)
    {
        if (!node) //if null then return nullptr
            return nullptr;
        
        if(oldtonew.count(node)) //if a copy already exists for node then return that copy so that it gets attached and duplicate is not created
        {
            return oldtonew[node];
        }

        Node* copy = new Node(node->val);//if not then make a copy
        oldtonew[node] = copy;//and then add it to map so that we dont repeat it
        for (Node* neigh : node->neighbors)//and then also add all the original neighbors of node to copy by using recursion
        {
            copy->neighbors.push_back(dfs(neigh, oldtonew));//we again recursively call dfs fn to add neighbors to copy
        }
        return copy;//return the cloned node
    }
};
