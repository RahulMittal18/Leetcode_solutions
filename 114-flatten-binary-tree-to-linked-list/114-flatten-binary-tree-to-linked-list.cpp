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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode *tail,*temp = root->right;
        if(root->left){
            flatten(root->left);
            tail=root->left;
            while(tail->right){
                tail=tail->right;
            }
            root->right = root->left;
            tail->right = temp;
            root->left = NULL;
        }
        flatten(root->right);
        
    }
};