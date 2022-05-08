/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* rightnode = nullptr;
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* popped = q.front();
                q.pop();
                popped->next = rightnode;
                rightnode = popped;
                if(popped->right) q.push(popped->right);
                if(popped->left) q.push(popped->left);
            }
        }
        return root;
    }
};