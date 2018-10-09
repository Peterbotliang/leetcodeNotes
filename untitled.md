# Leetcode 899

## Question

A string `S` of lowercase letters is given.  Then, we may make any number of _moves_.

In each move, we choose one of the first `K` letters \(starting from the left\), remove it, and place it at the end of the string.

Return the lexicographically smallest string we could have after any number of moves.

**Example 1:**

```text
Input: S = "cba", K = 1
Output: "acb"
Explanation: 
In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".
```

**Example 2:**

```text
Input: S = "baaca", K = 3
Output: "aaabc"
Explanation: 
In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".
```



## Solution

* When `K = 1` , rotate the string to get all possible strings and find out the smallest one.
* When `K > 1` , we can swap any two characters in the string. Therefore, we can get the smallest string by simply sorting it.

## Proof of the case K &gt; 1

Consider the most strict case `K = 2` , and the string is `baced` . We now want to swap `a` and `e` so that it becomes `becad` :

* Move the first character that you want to swap \(in this case it is `a` \) to the head of the string. \(`baced` -&gt; `acedb` \)
* Put all the characters between the two characters you want to swap  \(in this case, we get one, that is `c` \) to the end of the string one by one. \(`acedb` -&gt; `aedbc` \)
* Put the first character \(`a` \) to the end. \(`aedbc` -&gt; `edbca` \)
* Put all characters that is between the second character that you want to swap to the first \(from `e` to `c` \) in the original string \(in this case, we have `d` and `b`\) to the end. \(`edbca` -&gt; `ecadb` \)
* Rotate it back. \(`ecadb` -&gt; `becad` \)

By following steps mentioned above, we can swap any two characters in the string.



## Code

[899.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/899.cpp)

```text
class Solution {
public:
    string orderlyQueue(string S, int K) 
    {
        string result = "";
        if (K > 1)
        {
            vector<int> freq(26, 0);
            for (int i = 0; i < S.size(); i++)
                freq[S[i] - 'a']++;
            
            for (int i = 0; i < 26; i++)
                result += string(freq[i], (char)(i + 'a'));    
            return result;
        }
        
        result = S;
        for (int i = 0; i < S.size(); i++)
        {
            char ch = S.front();
            S.erase(0, 1);
            S += ch;
            result = min(S, result);
        }
        return result;
    }
};
```

