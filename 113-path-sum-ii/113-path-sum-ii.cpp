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
    vector<vector<int>>ans;
    void helper(TreeNode* root,vector<int> temp,int target){
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left and !root->right and target==root->val) {
            ans.push_back(temp);
            return;
        }
        helper(root->left,temp,target-root->val);
        helper(root->right,temp,target-root->val);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root,{},targetSum);
        return ans;
    }
};