class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xorSum = 0;
        for (int &num : nums)
            xorSum ^= num;
        
        int a = xorSum & (~(xorSum - 1)); //get the rightmost set bit
        
        int x = 0;
        int y = 0;
        for (int &num : nums)
        {
            if (a & num)
                x ^= num;
            else
                y ^= num;
        }
        
        vector<int> result;
        result.push_back(x);
        result.push_back(y);
        return result;
    }
};
