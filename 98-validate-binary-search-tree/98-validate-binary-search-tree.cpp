class Solution {
public:
    
    bool check(TreeNode* root, long long min, long long max){
        if(root==NULL) return true;
        
        return (min < root->val && root->val < max) && (check(root->left, min, root->val)) && (check(root->right, root->val, max));
    }
    
    
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};