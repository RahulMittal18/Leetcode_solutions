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
    TreeNode* st;
    bool search(TreeNode* root,int x){
        if(!root) return false;
        if(root->val==x){
            st=root;
            return true;
        }
        
        bool left = search(root->left,x);
        if(left) return true;
        bool right = search(root->right,x);
        return right;
    }
    
    int count(TreeNode* root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        search(root,x);
        int p = count(st->left);
        int q = count(st->right);
            
        if(p>n/2 or q>n/2 or n-p-q-1 >n/2) return true;
        return false;
    }
};