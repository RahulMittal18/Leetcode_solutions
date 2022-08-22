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
    
//     int height(TreeNode* root,int start,TreeNode** startI){
//         if(!root) return 0;
//         if(root->val==start) *startI = root;
//         return 1 + max(height(root->left,start,startI),height(root->right,start,startI));
//     }
    
//     int amountOfTime(TreeNode* root, int start) {
//         if(!root || !root->left && !root->right) return 0;
//         TreeNode* startI = NULL;
//         bool from_left = false;
//         int lh = height(root->left,start,&startI);
//         if(startI!=NULL) from_left=true;
//         int rh = height(root->right,start,&startI);
//         int belowStart = height(startI,start,&startI);
//         if(root->val==start) return max(lh,rh);
//         else if(from_left) return max(belowStart-1,rh+lh-belowStart+1);
//         else return max(belowStart-1,lh+rh-belowStart+1);
//     }
    TreeNode* s=NULL;
    void mapParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* par,int start){
        if(!root) return;
        if(root->val==start) s=root;
        parent[root]=par;
        mapParents(root->left,parent,root,start);
        mapParents(root->right,parent,root,start);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_set<TreeNode*> vis;
        vis.insert(NULL);
        mapParents(root,parent,NULL,start);
        queue<TreeNode*> q;
        int ans = 0;
        q.push(s);
        vis.insert(s);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto p = q.front();
                q.pop();
                if(p->left && vis.count(p->left)==0){
                    vis.insert(p->left);
                    q.push(p->left);
                }
                if(p->right && vis.count(p->right)==0){
                    vis.insert(p->right);
                    q.push(p->right);
                }
                if(vis.count(parent[p])==0){
                    vis.insert(parent[p]);
                    q.push(parent[p]);
                }
            }
            ans++;
        }
        return ans-1;
    }
};