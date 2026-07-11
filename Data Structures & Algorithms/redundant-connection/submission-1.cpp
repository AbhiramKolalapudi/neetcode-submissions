class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {//we basically use a disjoint set union (union-find) to find cycle which is basically an array that stores parent of a node of the graph
     //we first initialise all elements parents as themselves, and then add the edges one by one and incase any 2 edges have the same root parent before we do union to them then they would form a cycle and hence we return that edge
        vector<int> parent = buildDSU(edges.size() + 1);

        for (auto& e : edges)
        {
            if (findDSU(parent, e[0]) != findDSU(parent, e[1]))
                unionDSU(parent, e[1], e[0]);
            else
            {
                return e;
            }
        }
        return {};

    }

private:
    vector<int> buildDSU(int len)
    {
        vector<int>parent(len);
        for (int i = 0; i < len; i++)
        {
            parent[i] = i;
        }
        return parent;
    }

    void unionDSU(vector<int>& parent, int i, int j)
    {
        int rooti = findDSU(parent, i);
        int rootj = findDSU(parent, j);

        parent[rootj] = rooti;
    }

    int findDSU(vector<int>& parent, int i)
    {
        while (parent[i] != i)
        {
            i = parent[i];
        }
        return i;
    }
};
