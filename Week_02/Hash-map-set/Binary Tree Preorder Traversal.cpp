/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //前序遍历：根左右
 //递归
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        preOreder(root);
        return res;
    }
    void preOreder(TreeNode*root) {
        if(root==NULL)
            return;
        res.push_back(root->val);
        preOreder(root->left);
        preOreder(root->right);
        return;
    }  
};
//栈
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(!st.empty()||root) {
            while(root) {
                st.push(root);
                res.push_back(root->val);
                root=root->left;
            }
            root=st.top();
            st.pop();
            root=root->right;
        }
        return res;
    }  
};