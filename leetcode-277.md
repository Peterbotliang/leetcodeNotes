---
description: Find the Celebrity
---

# Leetcode 277

## Question

Suppose you are at a party with `n` people \(labeled from `0` to `n - 1`\) and among them, there may exist one celebrity. The definition of a celebrity is that all the other `n - 1` people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity \(or verify there is not one\) by asking as few questions as possible \(in the asymptotic sense\).

You are given a helper function `bool knows(a, b)` which tells you whether A knows B. Implement a function `int findCelebrity(n)`, your function should minimize the number of calls to `knows`.

**Note**: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return `-1`.



## Solution

The key idea of solving this problem is to find out a possible candidate of celebrity in the first pass, and to verify it in the second pass.

To find out a candidate in one pass, we first assume a candidate `j` . In the first pass, for each person `i` that `i != j` , we have the following rules:

*  If `j knows i` , `j` is impossible to be a celebrity. We set `j = i` ;
* If `j does not know i` , `i` is impossible to be a celebrity.

Finally, `j` becomes the label of the person who may be that celebrity.

In the second pass we just need to verify whether all the other `n - 1` people know him/her but he/she does not know any of them.

The total time complexity will be `O(n)` .



## Code

[277.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/277.cpp)

```text
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) 
    {
        int celebrity = 0;
        // Find the possible celebrity
        for (int i = 0; i < n; i++)
        {
            if (knows(celebrity, i))
                celebrity = i;
        }
        
        // Verify celebrity
        for (int i = 0; i < n; i++)
        {
            if (i != celebrity)
            {
                if (!knows(i, celebrity) || knows(celebrity, i))
                    return -1;
            }
        }
        return celebrity;
    }
};
```

