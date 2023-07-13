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
    int ls(int st,int end,vector<int> &preorder,int x){
        for(int i=st;i<=end;i++){
            if(preorder[i]>x) return i-1;
        }
        return end;
    }
    
    TreeNode* buildTree(int st,int end,vector<int> &preorder){
        if(st>end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[st]);
        if(st==end) return root;
        
        int p = ls(st+1,end,preorder,preorder[st]);
        
        root->left = buildTree(st+1,p,preorder);
        root->right = buildTree(p+1,end,preorder);
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return buildTree(0,n-1,preorder);
    }
};