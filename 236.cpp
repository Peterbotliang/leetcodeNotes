class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<pair<int, int> > DQ; // first for value, second for position
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            while(!DQ.empty() && DQ.front().second <= max(-1, i - k))
                DQ.pop_front();
            while(!DQ.empty() && DQ.back().first <= nums[i])
                DQ.pop_back();
            DQ.push_back(pair<int, int>(nums[i], i));
            if (i >= k - 1)
                result.push_back(DQ.front().first);
        }
        return result;
    }
};
