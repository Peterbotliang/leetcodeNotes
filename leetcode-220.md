# Leetcode 220

## Question

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the **absolute** difference between **nums\[i\]** and **nums\[j\]** is at most t and the **absolute** difference between i and j is at most k.

**Example 1:**

```text
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
```

**Example 2:**

```text
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
```

**Example 3:**

```text
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
```

\(i.e. if there exists two integer `i` and `j` , such that `|num[i] - num[j]| <= t` and `|i - j| <= k` , return `true` . Otherwise return `false` .          



## Solution

The most straightforward solution is calculating all possible differences between numbers in a sliding window of size `k` . The time complexity is $$O(k^2 n)$$. Another solution is using a hash map `m` , with the number `num[i]` as the key and its position `i` as the value, to store the positions of the numbers. Each time, for a number `num[j]` , we should find whether `num[j] - t, num[j] - t + 1, ... , num[j], ... , num[j] + t`  are in the hash map, and whether there position difference is less or equal `k` . Again, the time complexity of this algorithm is $$O(tn)$$, which is not desirable.

Actually we can make some improvement to the second algorithm. Noticing that `|num[i] - num[j]| <= t` is equivalent to `|num[i] / t - num[j] / t| <= 1` , we can make `num[i] / t`  the key, instead of `num[i]` , with which, each time for a number `num[j]` , we only need to find whether `num[j] / t - 1, num[j] / t, num[j] / t + 1` is in the hash map. The point is that now in the hash map we need to store both the position `j` and its real value `num[j]` , because there many different values that may map to the same key and we need to store the real values to figure out whether the difference is at most `t` 

**P.S.**

1. Don't forget to handle the special condition `t = 0` .
2. Sometimes the `int` type in C++ may overflow.  For example, the case `[-1, 2^31 - 1], k = 1, t = 2^31 - 1` . In this solution I use `long long` as a workaround. There should be a better way to do that :\).          

## Code                     

[220.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/220.cpp)

```text
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
```



