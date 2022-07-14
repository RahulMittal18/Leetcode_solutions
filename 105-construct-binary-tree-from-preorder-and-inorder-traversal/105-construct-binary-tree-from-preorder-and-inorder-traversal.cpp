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
    int ind = 0;
    int search(vector<int> &inorder, int key){
        for(int i = 0;i<inorder.size();i++){
            if(inorder[i]==key) return i;
        }
        return 0;
    }
    
    
    TreeNode* build(int &ind,vector<int> &preorder, vector<int> &inorder, int st , int end){
        if(st>end) return nullptr;
        int indx = search(inorder,preorder[ind]);
        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = build(ind,preorder,inorder,st,indx-1);
        root->right = build(ind,preorder,inorder,indx+1,end);
        return root;
    }
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n==0) return nullptr;
        return build(ind,preorder,inorder,0,n-1);
    }
};