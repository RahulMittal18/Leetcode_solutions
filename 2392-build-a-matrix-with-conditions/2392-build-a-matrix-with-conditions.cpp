class Node {
   public:
  int value;
  Node* next;
    Node(int x) : value(x), next(nullptr) {}
};

class Solution {
public:

bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
      vis[node] = 1;
      dfsVis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkCycle(it, adj, vis, dfsVis)) return true;
        } else if (dfsVis[it]) {
          return true;
        }
      }
      dfsVis[node] = 0;
      return false;
    }
    
void dfs(int cur, int par,vector<int>&vis1,vector<int> &order1,vector < int > gr1[]) {
	vis1[cur] = 1;
	for (auto x : gr1[cur]) {
		if (!vis1[x]) {
			dfs(x, cur,vis1,order1,gr1);
		}
	}
	order1.push_back(cur);
	return;
}
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        map<int,int> mp,colmap;
        bool flag=false;
        vector<vector<int>> ans(k,vector<int>(k,0));
        vector<int> order;
        vector<int> gr1[k+1],gr2[k+1];
        for(int i=0;i<row.size();i++){
            gr1[row[i][0]-1].push_back(row[i][1]-1);
        }
        for(int i=0;i<col.size();i++){
            gr2[col[i][0]-1].push_back(col[i][1]-1);
        }
        int vis[k], dfsVis[k];
          memset(vis, 0, sizeof vis);
          memset(dfsVis, 0, sizeof dfsVis);

        for (int i = 0; i < k; i++) {
            if (!vis[i]) {
              if (checkCycle(i, gr1, vis, dfsVis)) {
                flag= true;
                  break;
              }
            }
          }
        memset(vis, 0, sizeof vis);
          memset(dfsVis, 0, sizeof dfsVis);

        for (int i = 0; i < k; i++) {
            if (!vis[i]) {
              if (checkCycle(i, gr2, vis, dfsVis)) {
                flag= true;
                  break;
              }
            }
          }
        if(flag) return {};
        vector<int> vis1(k,0),vis2(k,0);
        vector<int> order1,order2;
        for (int i = 0; i < k; i++) {
		if (!vis1[i]) dfs(i, 0,vis1,order1,gr1);
	    }
        reverse(order1.begin(), order1.end());
        
        for (int i = 0; i <k; i++) {
		if (!vis2[i]) dfs(i, 0,vis2,order2,gr2);
	    }
        reverse(order2.begin(), order2.end());
        for(auto x:order1) cout<<x<<" ";
        cout<<endl;
                for(auto x:order2) cout<<x<<" ";
        cout<<endl;
        for(int i=0;i<k;i++){
            ans[i][0]=order1[i]+1;
            mp[order1[i]+1] = i;
        }
        int j=0;
        for(int i=0;i<k;i++){
            swap(ans[mp[order2[i]+1]][0],ans[mp[order2[i]+1]][j]);
            j++;
        }
        
        return ans;
    }
};