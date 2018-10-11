class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        // if (nums.size() <= 2)
        //     return nums;
        
        int A, B;
        int countA = 0;
        int countB = 0;
        
        for (int &num : nums)
        {
            if (num == A)
                countA++;
            else if (num == B)
                countB++;
            else if (countA == 0)
            {
                A = num;
                countA = 1;
            }
            else if (countB == 0)
            {
                B = num;
                countB++;
            }
            else
            {
                countA--;
                countB--;
            }
        }
        
        countA = 0;
        countB = 0;
        vector<int> result;
        for (int &num : nums)
        {
            if (num == A)
                countA++;
            else if (num == B)
                countB++;
        }
        
        if (countA > nums.size() / 3)
            result.push_back(A);
        if (countB > nums.size() / 3)
            result.push_back(B);
        return result;
    }
};
