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
    
    bool check(TreeNode* root, TreeNode* &prev){
        if(root==NULL) return true;
        bool leftValid = check(root->left,prev);
        if(prev && prev->val >= root->val)
            return false;
        prev = root;
        bool rightValid = check(root->right,prev);
        return leftValid && rightValid;
    }
    
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return check(root,prev);
    }
};