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
    // root is leaf
    #define NO_cam 0
    #define Has_cam 1
    //root is null
    #define NO_need 2
    int ans=0;
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==NO_cam)ans++;
        return ans;
    }
    int dfs(TreeNode* root){
        if(!root)
            return NO_need;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(l==NO_cam || r==NO_cam){
            ans++;
            return Has_cam;
        }
        else if(l==Has_cam || r== Has_cam){
            return NO_need;
        }
        else
            return NO_cam;
    }
};