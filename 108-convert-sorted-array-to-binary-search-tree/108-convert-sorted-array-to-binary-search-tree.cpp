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
    
    TreeNode* build(vector<int> &nums,int st,int end){
        if(st>end) return nullptr;
        int mid = st + (end-st)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(st==end) return root;
        root->left = build(nums,st,mid-1);
        root->right = build(nums,mid+1,end);
        return root;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return nullptr;
        
        return build(nums,0,n-1);
    }
};