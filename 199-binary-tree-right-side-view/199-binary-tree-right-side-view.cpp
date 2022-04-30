/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int level, vector<int> &ans){
        if(root==NULL)
            return;
        
        if(level==ans.size())
            ans.push_back(root->val);
        
        helper(root->right,level+1,ans);
        helper(root->left,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root,0,ans);
        return ans;
    }
};