//二叉树的中序遍历方式，左-->根-->右
//方法一：递归
//递归终止条件为节点为空。
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        inorderT(root);
        return res;
    }
    void inorderT(TreeNode*root) {
        //递归终止条件
        if(root==nullptr)
            return;
        inorderT(root->left);
        res.push_back(root->val);
        inorderT(root->right);
        return;
    }
   
};
//方法二：把每个节点的左子节点压入栈中
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> res;
       stack<TreeNode*> st;
       while(root||!st.empty()){
            //把某个节点的全部左子节点放入栈中
            while(root!=nullptr) {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();//
            res.push_back(root->val);
            root=root->right;
       }
       return res;
    }  
};