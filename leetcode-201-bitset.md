# Leetcode 201 \(bitset\)

## Question

Given a range \[m, n\] where 0 &lt;= m &lt;= n &lt;= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

**Example 1:**

```text
Input: [5,7]
Output: 4
```

**Example 2:**

```text
Input: [0,1]
Output: 0
```



## Key Idea

The point to solve this problem is to find out the "common left header" \(i.e. the common high bits\), and set the remaining bits to 0.

## Solution 1 \(using bitset\)

1. Convert `m` and `n` to 32-bit binary number `m2` and `n2` respectively, using `bitset<32>` . 
2. Starting from the MSB \(Most Significant Bit\), find out the first index `i` where `m2` and `n2` are different \(i.e. `m2[i] != n2[i]` \).
3. Keep all the bits that is higher than `i` , while setting all the bits that is lower or equal to `i` to 0. The result is the answer of the question.

## Code 1

[201.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/201.cpp)

```text
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        bitset<32> m2(m);
        bitset<32> n2(n);

        int i;
        for (i = 31; i >= 0; i--)
        {
            if (m2[i] != n2[i])
                break;
        }
        
        m2 &= ~(bitset<32>((int)(pow(2, i + 1)) - 1));
        return m2.to_ulong();
    }
};
```

            

## Solution 2 \(faster\)

Unset the lower set bits in `n` until it becomes less than or equal to `m` , using AND.



## Code 2

[201b.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/201b.cpp)

```text
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        while (m < n)
        {
            n &= n - 1;
        }
        return n;
    }
};
```

