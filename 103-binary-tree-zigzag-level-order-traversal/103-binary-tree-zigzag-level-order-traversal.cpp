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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        bool l2r=true;
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i=0;i<n;i++){
                TreeNode* popped = q.front();
                if(l2r) temp[i] = popped->val;
                else temp[n-i-1] = popped->val;
                q.pop();
                if(popped->left) q.push(popped->left);
                if(popped->right) q.push(popped->right);
            }
            l2r=!l2r;
            ans.push_back(temp);
        }
        return ans;
    }
};