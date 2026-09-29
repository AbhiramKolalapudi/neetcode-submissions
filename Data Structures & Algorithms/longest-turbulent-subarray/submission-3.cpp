class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0;
        int r = 1;
        int res = 1;
        int prev = 0; //0 means uninitialised and 1 is > and 2 is <

        while (r < arr.size())
        {
            if ((prev == 0 || prev == 2) && arr[r-1] > arr[r])
            {
                prev = 1;
                r++;
            }

            else if ((prev == 0 || prev == 1) && arr[r-1] < arr[r])
            {
                prev = 2;
                r++;
            }

            else
            {
                res = max(res, r - l);
                if (arr[r-1] == arr[r])
                    r++;
                l = r - 1;
                prev = 0;
            }
        }
        res = max(res, r - l);
        return res;
    }
};