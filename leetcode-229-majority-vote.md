---
description: Majority Element II
---

# Leetcode 229 \(Majority Vote\)

## Question

Given an integer array of size n, find all elements that appear more than `⌊ n/3 ⌋` times.

**Note:** The algorithm should run in linear time and in O\(1\) space.

**Example 1:**

```text
Input: [3,2,3]
Output: [3]
```

**Example 2:**

```text
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
```



## Solution

In this problem we use an improved version of Boyer-Moore majority vote algorithm. We use two variable `A` and `B` to store the current two majority numbers, and `countA` , `countB` as the counters. It only needs to go through two passes of the array.

In the first pass, for each element `x` in the array, the steps go as follows

* When `x == A -> countA++` , or `x == B -> countB++` ;
* When `countA == 0 -> A = x, countA = 1` , or `countB == 0 -> B = x, countB = 1` ;
* Otherwise, `countA--, countB--` .           
* **P.S.** Don't get into the case `A == B`

This algorithm guarantees that it the majority number exists, it must be either in `A` or `B` \(And there are at most 2 majority numbers. In the second pass, we simply count the numbers of `A`and `B` to check whether they are real majority numbers of not.



## Code

[229.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/229.cpp)

```text
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
```

