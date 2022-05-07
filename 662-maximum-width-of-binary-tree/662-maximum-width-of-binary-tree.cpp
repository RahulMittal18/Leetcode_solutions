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
    
int widthOfBinaryTree(TreeNode * root) {
  if (!root) return 0;
  int ans = 0;
  queue <pair<TreeNode*,long long int>> q;
  q.push({ root,0ll });
  while(!q.empty()){
    int size = q.size();
    long long int curMin = q.front().second;
    int leftMost, rightMost;
    for (int i=0; i<size; i++) {
      long long int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      TreeNode * temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size-1) rightMost = cur_id;
      if(temp->left)  q.push({ temp->left, cur_id*2 + 1 });
      if(temp->right) q.push({ temp->right, cur_id*2 + 2 });
    }
    ans = max(ans, rightMost-leftMost+1);
  }
  return ans;
}
};