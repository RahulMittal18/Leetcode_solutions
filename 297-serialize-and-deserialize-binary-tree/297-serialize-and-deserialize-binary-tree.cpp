/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* popped = q.front();
            q.pop();
            if(!popped) s+="#,";
            if(popped){
                s+=to_string(popped->val);
                s+=",";
                q.push(popped->left);
                q.push(popped->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* popped = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#") popped->left = nullptr;
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                popped->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="#") popped->right=nullptr;
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                popped->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));