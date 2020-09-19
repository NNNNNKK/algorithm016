/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归，子问题是左子树和右子树深度的最大值，最大值加1就是树的最大深度
 //时间复杂度为O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //递归终止条件
        if(!root)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};