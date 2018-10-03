class Solution 
{
    struct Entry
    {
        long long val;
        long long pos;
        Entry(int x = -1, int y = -1) : val(x), pos(y) {}
    };
    
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        if (nums.empty())
            return false;
        unordered_map<int, Entry> m;
        m[nums.front() / max(1, t)] = Entry(nums.front(), 0);
        
        for (int i = 1; i < nums.size(); i++)
        {
            int key = nums[i] / max(1, t);
            if (m.find(key - 1) != m.end())
            {
                if (abs(m[key - 1].val - nums[i]) <= t && abs(m[key - 1].pos - i) <= k)
                    return true;
            }
            
            if (m.find(key + 1) != m.end())
            {
                if (abs(m[key + 1].val - nums[i]) <= t && abs(m[key + 1].pos - i) <= k)
                    return true;
            }
            
            if (m.find(key) != m.end())
            {
                if (abs(m[key].val - nums[i]) <= t && abs(m[key].pos - i) <= k)
                    return true;
            }
            m[key] = Entry(nums[i], i);
        }
        return false;
    }
};
