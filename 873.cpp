class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) 
    {
        vector<vector<int> > dp(A.size());
        for (int i = 0; i < dp.size(); i++)
        {
            dp[i] = vector<int>(A.size(), 0);
        }
        
        unordered_map<int, int> pos;
        for (int i = 0; i < A.size(); i++)
        {
            pos[A[i]] = i;
        }
        
        int result = 0;
        for (int i = 0; i < A.size() - 2; i++)
        {
            for (int j = i + 1; j < A.size() - 1; j++)
            {
                if (pos.find(A[i] + A[j]) != pos.end())
                {
                    int k = pos[A[i] + A[j]];
                    dp[j][k] = max(dp[j][k], dp[i][j] + 1);
                    result = max(result, dp[j][k]);
                }
            }
        }
        if (result)
            return result + 2;
        else
            return result;
    }
};
