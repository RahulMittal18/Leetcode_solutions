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
    void mapParents(TreeNode* root,TreeNode* par, map<TreeNode*,TreeNode*> &mp){
        if(!root) return;
        mp[root] = par;
        mapParents(root->left,root,mp);
        mapParents(root->right,root,mp);
    }
    
    void solveChild(TreeNode* root, int d,vector<int> &ans,set<TreeNode*> &vis){
        if(!root || vis.count(root)) return;
        
        vis.insert(root);

        if(d==0){
            ans.push_back(root->val);
            return;
        }
        solveChild(root->left,d-1,ans,vis);        
        solveChild(root->right,d-1,ans,vis);
    }
    
    void solvePar(TreeNode* root, int d,TreeNode* par, vector<int> &ans, map<TreeNode*,TreeNode*> &mp,set<TreeNode*> &vis){
        if(d==0) {
            ans.push_back(root->val);
            return;
        }
        if(mp[root]==root) {
            solveChild(root,d,ans,vis);
            return;
        }
        vis.insert(root);
        solvePar(mp[root],d-1,root,ans,mp,vis);
        solveChild(root->left,d-1,ans,vis);        
        solveChild(root->right,d-1,ans,vis);

    }
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return vector<int> {target->val};
        map<TreeNode*, TreeNode*> pcmap;
        set<TreeNode*> vis;
        mapParents(root,root,pcmap);
        vector<int> ans;
        solveChild(target,k,ans,vis);
        solvePar(target,k,target,ans,pcmap,vis);
        return ans;
    }
};