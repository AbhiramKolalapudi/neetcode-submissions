class Solution {
public:
    bool checkValidString(string s) 
    { //we have 2 numbers, max_open will have the max number of opened parathesis we can have and min_open will have the min
      //if max ever goes -ve that means we return false
      //and after checking every character if min is negative we make it 0 as we can have negative no. of opened parathesis (i.e. so that we dont return "(**(" as true)
      //at last return min_open == 0 as max_open doesnt matter as long as its +ve which we checked inside loop
        int max_open = 0;
        int min_open = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                max_open++;
                min_open++;
            }
            
            else if (c == ')')
            {
                max_open--;
                min_open--;
            }

            else if (c == '*')
            {
                max_open++;
                min_open--;
            }
            if (max_open < 0)
                return false;

            min_open = max(min_open, 0);
        }
        return min_open == 0;
    }
};
