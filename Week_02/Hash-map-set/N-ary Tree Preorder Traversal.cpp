/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//前序遍历，根--->左---->右
//递归法
class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        preO(root);
        return res;
    }
    void preO(Node* root) {
        if(!root)
            return;
        res.push_back(root->val);
        for(int i=0;i<root->children.size();i++) {
            preO(root->children[i]);
        }
        return;
    }
};
//迭代法
class Solution {
public:
    
    vector<int> preorder(Node* root) {
        if(!root)
            return {};
        vector<int> res;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node *temp=st.top();
            st.pop();
            res.push_back(temp->val);
            for(int i=temp->children.size()-1;i>=0;i--)
                st.push(temp->children[i]);
        }
        return res;
    }
};


