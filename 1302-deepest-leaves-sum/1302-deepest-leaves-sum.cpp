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
    int height(TreeNode* root){
        if(!root)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int h = height(root);
        int lvl=0,sum=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            lvl++;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* popped = q.front();
                if(lvl==h)
                sum+=popped->val;
                q.pop();
                if(popped->left) q.push(popped->left);
                if(popped->right) q.push(popped->right);
            }
        }
        return sum;
    }
};