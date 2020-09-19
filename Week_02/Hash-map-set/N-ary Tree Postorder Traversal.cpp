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
//递归解法
class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        postO(root);
        return res;
    }
    void postO(Node*root) {
        if(!root)
            return;
        for(int i=0;i<root->children.size();i++) {
            postO(root->children[i]);
        }
        res.push_back(root->val);
        return;
    }
};
//栈+迭代
vector<int> postorder(Node* root) {
    if(root==NULL) return {};
    vector<int> res;
    stack<Node*> stk;
    stk.push(root);
    while(!stk.empty())
    {
        Node* temp=stk.top();
        stk.pop();
        for(int i=0;i<temp->children.size();i++) 
            stk.push(temp->children[i]);
        res.push_back(temp->val);
    }
    reverse(res.begin(), res.end());
    return res;
}