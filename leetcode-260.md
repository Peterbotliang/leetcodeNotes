---
description: Single Number III
---

# Leetcode 260

## Question

Given an array of numbers `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

**Example:**

```text
Input:  [1,2,1,3,2,5]
Output: [3,5]
```

**Note**:

1. The order of the result is not important. So in the above example, `[5, 3]` is also correct.
2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?



## Solution \(using XOR\)

Thanks for [rohanrc1997](https://leetcode.com/rohanrc1997/)'s sharing of this amazing solution: [https://leetcode.com/problems/single-number-iii/discuss/144909/Bitwise-XOR-O\(n\)-time-and-O\(1\)-space-in-C++-Explained-\(-Beats-100\)](https://leetcode.com/problems/single-number-iii/discuss/144909/Bitwise-XOR-O%28n%29-time-and-O%281%29-space-in-C++-Explained-%28-Beats-100%29).

The key point is that if a number XOR itself, it becomes 0. Thus, supposing the two numbers that appear once are `x` and `y` respectively, after XOR all the numbers, we get `x XOR y` . 

The separate `x` and `y` in `x XOR y` , we notice that in XOR result, the set bits indicate that at these bits `x` and `y` are different \(e.g. `x = 0100` and `y = 1101` , then `x XOR y = 1001` . The first and the fourth bit of `x XOR y` are 1s, which means that the first and fourth bit of `x` and `y` are different\).

We then generate a new number `a` that has only one of the set bits in `x XOR y` , \(e.g. for `x XOR y = 1001` , `a = 1000` or `a = 0001` \). Here we use the rightmost set bit for `a` . We then separate the numbers into two sets by bitwise AND them with `a` . `x` and `y` will definitely not be in the same set. Now we XOR the two sets of numbers respectively and get the two number that only appear once.



## Code

[260.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/260.cpp)

```text
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
```

