class Solution {
public:
    int find(int u,vector<int> &parent){
        if(parent[u]<0)
            return u;
        
        parent[u]=find(parent[u],parent);
        return parent[u];
    }
    
    bool union_by_weight(int u,int v,vector<int> &parent){
        int pu=find(u,parent);
        int pv=find(v,parent);
        
        if(pu==pv)
            return 0;
        
        if(parent[pu]<parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv]=pu;   
        }
        else
        {
            parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
        return 1;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& e) {
        
        int i,n=e.size();
        vector<int> parent(n+1,-1);
        vector<int> in(n+1,-1);
        int e1=-1,e2=-1;
        
        for(i=0;i<n;i++)
        {
            if(in[e[i][1]]!=-1)         // indegree 2
            {
                e2=in[e[i][1]];         // first edge causing indegree 2
                e1=i;                   // second edge causing indegree 2
                break;
            }
            in[e[i][1]]=i;    
        }
    
        for(i=0;i<n;i++)
        {
            if(i==e1)       //ignore edge causing indegree
                continue;
            
            if(!union_by_weight(e[i][0],e[i][1],parent))     //cycle is present
            {
                if(e1!=-1)          //indegree 2 , wrong edge ignored
                    return e[e2];
                else                 //indegree 1 , remove edge causing cycle
                    return e[i];
            }
        }
        return e[e1];
    }
};