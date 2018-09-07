---
description: >-
  Given a linked list, return the node where the cycle begins. If there is no
  cycle, return NULL. Note: Do not modify the linked list. Can you solve it
  without using extra space?
---

# Leetcode 142

## Question

Given a linked list, return the node where the cycle begins. If there is no cycle, return `NULL`.

**Note:** Do not modify the linked list.

**Follow up**:  
Can you solve it without using extra space?

## Solution \(no extra space\)

Use to pointers `fast`  and `slow`  to traverse the linked list. Initially, `fast = slow = head` . Every time `fast`  moves 2 steps \(`fast = fast->next->next` \)forward, while `slow` moves 1 step \(`slow = slow->next`\) each time. If a cycle exists, `fast`  and `slow`  will meet each other \(i.e. `fast == slow` . Otherwise, `fast` will reach a N`ULL` pointer and return `NULL` .

* If `fast == NULL` , no cycle exists, return `NULL` .      
* If `fast == slow` , a cycle exists. Then we set `fast = head` and we move both `fast` and `slow` 1 step forward each time until they meet each other again \(i.e. `fast == slow` \). Now `fast` \(or `slow` \) points to the node that the cycle begins.  

## Proof of the solution

Suppose we have a cycle of $$k$$ nodes, and we have $$x$$ nodes in the linked list in front of the node that the cycle begins. If `fast` and `slow` meet each other, `fast` must be in the second loop of the cycle, while `slow` must be in the first loop of the cycle. We assume now `slow` still needs $$a$$ nodes to reach the node that begins the cycle.

* The nodes that `slow` has passed: $$k + x - a$$
* The nodes that `fast` has passed: $$2k + x - a$$
* As `fast` moves twice faster than `slow` ,  $$2(k + x - a) = 2k + x - a$$\(\*\)

Solving equation \(\*\), we have $$k = a$$. That's why the node that `fast` and `slow` meets is the node where the cycle begins.

## Code

[142.cpp](https://github.com/Peterbotliang/leetcodeNotes/blob/master/142.cpp)

```text
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *fast = head;
        ListNode *slow = head;
        
        do
        {
            if (fast != NULL)
                fast = fast->next;
            else
                return NULL;
            if (fast != NULL)
                fast = fast->next;
            else
                return NULL;
            slow = slow->next;
        } while(fast != slow);
        
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
```

