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
    void helper(TreeNode* root,vector<int> temp,int target,vector<vector<int>>& ans){
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left and !root->right and target==root->val) {
            ans.push_back(temp);
            return;
        }
        helper(root->left,temp,target-root->val,ans);
        helper(root->right,temp,target-root->val,ans);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        helper(root,{},targetSum,ans);
        return ans;
    }
};