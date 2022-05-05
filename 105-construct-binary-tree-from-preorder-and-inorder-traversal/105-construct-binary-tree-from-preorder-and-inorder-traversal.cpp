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
            int idx=0;

    int search(vector<int> inorder, int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (inorder[i] == value)
            return i;
    }
        return 0;
}
    
    TreeNode* solve(vector<int> preorder, vector<int> inorder,int st,int end ){
        if(st>end) return NULL;

        TreeNode* root = new TreeNode(preorder[idx++]);

        if(st==end) return root;
        int rootIndex = search(inorder,st,end, root->val);

        root->left = solve(preorder,inorder,st,rootIndex-1);
        root->right = solve(preorder,inorder,rootIndex+1,end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};