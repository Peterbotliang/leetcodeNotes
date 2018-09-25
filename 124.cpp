/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    int maxSum = INT_MIN;
public:
    int maxSearch(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftSum = maxSearch(root->left);
        int rightSum = maxSearch(root->right);

        this->maxSum = max(root->val, maxSum);
        this->maxSum = max(root->val + leftSum, maxSum);
        this->maxSum = max(root->val + rightSum, maxSum);
        this->maxSum = max(root->val + leftSum + rightSum, maxSum);
        return max(root->val, max(root->val + leftSum, root->val + rightSum));
    }
    int maxPathSum(TreeNode* root)
    {
        this->maxSum = max(maxSearch(root), maxSum);
        return this->maxSum;
    }
};
