class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> mp;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int col = q.front().second.first;
                int lvl = q.front().second.second;
                mp[col][lvl].insert(node->val);
                q.pop();
                if(node->left)
                    q.push({node->left,{col-1,lvl+1}});
                if(node->right)
                    q.push({node->right,{col+1,lvl+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto x:mp){
            vector<int>temp;
            for(auto y:x.second){
                temp.insert(temp.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};