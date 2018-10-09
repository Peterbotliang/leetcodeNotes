# Leetcode 873

## Question

A sequence `X_1, X_2, ..., X_n` is _fibonacci-like_ if:

* `n >= 3`
* `X_i + X_{i+1} = X_{i+2}` for all `i + 2 <= n`

Given a **strictly increasing** array `A` of positive integers forming a sequence, find the **length** of the longest fibonacci-like subsequence of `A`.  If one does not exist, return 0.

\(_Recall that a subsequence is derived from another sequence `A` by deleting any number of elements \(including none\) from `A`, without changing the order of the remaining elements.  For example, `[3, 5, 8]` is a subsequence of `[3, 4, 5, 6, 7, 8]`._\)

**Example 1:**

```text
Input: [1,2,3,4,5,6,7,8]
Output: 5
Explanation:
The longest subsequence that is fibonacci-like: [1,2,3,5,8].
```

**Example 2:**

```text
Input: [1,3,7,11,12,14,18]
Output: 3
Explanation:
The longest subsequence that is fibonacci-like:
[1,11,12], [3,11,14] or [7,11,18].
```

## Solution

We use 2D-dynamic programming\(DP\) to solve this problem.

* For a Fibonacci Subsequence that ends up with A\[i\] and A\[j\] \(i.e. the last two number of the sequence is A\[i\] and A\[j\]\), where i &lt; j, we use dp\[i\]\[j\] to write down the length of this Fibonacci Subsequence.
* If there exists a number A\[k\] so that A\[i\] + A\[j\] = A\[k\]. Then dp\[j\]\[k\] = dp\[i\]\[j\] + 1.          
* **For example,** for a sequence `1,2,3,4,5`  , A\[1\] = 2, A\[3\] = 4, A\[4\] = 5. dp\[1\]\[3\] = 3 \(sequence `1,2,3` \) and A\[1\] + A\[3\] = A\[4\]. Therefore dp\[3\]\[4\] = dp\[1\]\[3\] + 1 = 4 \(sequence `1,2,3,5` \). 

            

{% hint style="info" %}
To speed up the search, we use a hashmap to store the position of each number in the sequence.
{% endhint %}

## Code

[873.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/873.cpp)

```text
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
```



