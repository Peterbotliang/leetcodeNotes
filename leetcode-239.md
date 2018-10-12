---
description: Sliding Window Maximum
---

# Leetcode 239

## Question

Given an array _nums_, there is a sliding window of size _k_ which is moving from the very left of the array to the very right. You can only see the _k_ numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

**Example:**

```text
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**Note:**   
You may assume _k_ is always valid, 1 ≤ k ≤ input array's size for non-empty array.

**Follow up:**  
Could you solve it in linear time?



## Solution

It is quite easy to come up with a solution with time complexity `O(nlogk)` using heap. However, it can be optimized further. We now introduce a data structure called **Monotonic Queue** based on the double-end queue, with we can solve the problem by just passing the array once

Now we create a double-end queue `DQ` that stores a pair of integers `pair<int, int>`  for both the value of the number and the index of the number. For each element `nums[i]`  in the array, we do the following:

* Remove all the elements `<nums[j], j>` , the value of which is smaller than `nums[i]` \(i.e.`nums[j] < nums[i]` \), at the back `DQ` , since they are no longer able to be the maximum in the following sliding window.
* Remove all the elements `<nums[j], j>` , the index of of which is smaller than or equal to `i - k` , as they no longer in the window.
* Push `<nums[i], i>` , into `DQ` .
* The front of `DQ` stores the value of the maximum of the current window.

Such **Monotonic Queue** ensures that the value in `DQ` is monotonically decreasing, the index in `DQ` is monotonic increasing.  



## Code

[239.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/239.cpp)

```text
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
```

