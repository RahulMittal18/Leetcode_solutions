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
    
    void dfs(TreeNode* root,int i,int j,map<pair<int,int>,vector<int>> &mp){
        if(!root) return;
        mp[{j,i}].push_back(root->val);
        dfs(root->left,i+1,j-1,mp);
        dfs(root->right,i+1,j+1,mp);

    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<pair<int,int>,vector<int>> mp;
        dfs(root,0,0,mp);
        vector<vector<int>> ans;
        int prev = -10000;
        vector<int> temp;
        for(auto k:mp){
            vector<int> a = k.second;
            sort(a.begin(),a.end());
            if(prev==-10000 || k.first.first == prev){
                prev = k.first.first;
                temp.insert(temp.end(),a.begin(),a.end());
            }
            else{
                ans.push_back(temp);
                temp.clear();
                prev = k.first.first;
                temp.insert(temp.end(),a.begin(),a.end());
            }
        }
        ans.push_back(temp);
        return ans;
    }
};