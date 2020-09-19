//N叉树的层序遍历
//思路：① 用一个队列来存储每一层的节点。
//② 遍历该队列的节点，依次把每个节点的儿子节点放入队列中。

//codes:
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr)
            return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size=q.size();
            vector<int> curLevel;
            for(int i=0;i<size;i++) {
                Node*n=q.front();
                q.pop();
                curLevel.push_back(n->val);
                for(auto a:n->children)
                    q.push(a);
            }
            res.push_back(curLevel);
        }
        return res;
    }
};