class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) 
    {//first we add all possible triplets' index (all 3 numbers are either smaller or equal to target) to a vector.
     //and then see if our target[0], target[1] and target[2] are in the possible triplets and if yes then return true
        vector<int> possibletriplets;
        for (int i = 0; i < triplets.size(); i++)
        {
            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2])
                possibletriplets.push_back(i);
        }

        vector<bool> res(3, false);

        for (int i : possibletriplets)
        {
            if (triplets[i][0] == target[0])
                res[0] = true;
            
            if (triplets[i][1] == target[1])
                res[1] = true;

            if (triplets[i][2] == target[2])
                res[2] = true;
        }

        return (res[0] && res[1] && res[2]);
    }
};
