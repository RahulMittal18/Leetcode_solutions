/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    set<TreeNode*> vis;
    void mapParents(TreeNode* root, map<TreeNode*,TreeNode*>& parent){
        if(!root)
            return;
        if(root->left){
            parent[root->left]=root;
            mapParents(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            mapParents(root->right,parent);
        }
    }
    
    void solve(TreeNode* root, int k,map<TreeNode*,TreeNode*>& parent, vector<int>& ans){
        if(vis.count(root)) return;
        if(!root)
            return;
        vis.insert(root);
        if(k==0) {ans.push_back(root->val); return;}
        solve(parent[root],k-1,parent,ans);
        solve(root->left,k-1,parent,ans);
        solve(root->right,k-1,parent,ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent;
        parent[root]=nullptr;
        mapParents(root,parent);
        
        
        vector<int> ans;
        solve(target,k,parent,ans);
        return ans;
    }
};