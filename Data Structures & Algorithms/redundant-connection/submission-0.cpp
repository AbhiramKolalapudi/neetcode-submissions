class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        vector<int> parent = buildDSU(edges.size() + 1);

        for (auto& e : edges)
        {
            if (finddsu(parent, e[0]) != finddsu(parent, e[1]))
                uniondsu(parent, e[1], e[0]);
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

    void uniondsu(vector<int>& parent, int i, int j)
    {
        int rootA = finddsu(parent, i);
        int rootB = finddsu(parent, j);

        parent[rootB] = rootA;
    }

    int finddsu(vector<int>& parent, int i)
    {
        if (parent[i] == i)
            return i;
        else
            return finddsu(parent, parent[i]);
    }
};
