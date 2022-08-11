class Solution {
public:  
    
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* prev = NULL;
        while( root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            TreeNode* popped = st.top();
            st.pop();
            
            if(prev && prev->val >= popped->val) return false;
            prev = popped;
            root = popped->right;
        }
        return true;
    }
};