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
    void solve(int &count, int mx,TreeNode* root){
        if(!root) return;
        solve(count,max(mx,root->val),root->left);
        if(root->val>=mx) count++;
        solve(count,max(mx,root->val),root->right);
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(count,-100000,root);
        return count;
    }
};