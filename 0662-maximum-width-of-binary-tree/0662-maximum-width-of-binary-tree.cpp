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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
    queue<pair<TreeNode*,long long>> q;
    q.push({root,0});
    int ans = 0;
    while(!q.empty()){
        int n = q.size();
        int cur_min = q.front().second;
        int leftmost=0,rightmost=0;
        for(int i=0;i<n;i++){
            auto x = q.front().first;
            int ind = q.front().second -cur_min;
            q.pop();
            if(i==0) leftmost = ind;
            if(i==n-1) rightmost = ind;
            if(x->left) q.push({x->left,2ll*ind+1});
            if(x->right) q.push({x->right,2ll*ind+2});
        }
        ans=max(ans,rightmost-leftmost+1);
    }
    return ans;
    }
};