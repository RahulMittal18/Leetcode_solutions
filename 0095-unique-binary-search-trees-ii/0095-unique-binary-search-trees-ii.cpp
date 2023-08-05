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
    vector<TreeNode*> solve(int l,int r,map<pair<int,int>,vector<TreeNode*>>&dp){
        vector<TreeNode*> res;
        if(l>r){
            res.push_back(NULL);
            return res;
        }
        
        if(dp.find({l,r})!=dp.end()) return dp[{l,r}];

        for(int i=l;i<=r;i++){
            vector<TreeNode*> left = solve(l,i-1,dp);
            vector<TreeNode*> right = solve(i+1,r,dp);
        
            for(auto ls:left){
                for(auto rs:right){
                    TreeNode* root = new TreeNode(i,ls,rs);
                    res.push_back(root);
                }
            }
        }
        return dp[{l,r}] = res;
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>,vector<TreeNode*>> dp;
        return solve(1,n,dp);
    }
};