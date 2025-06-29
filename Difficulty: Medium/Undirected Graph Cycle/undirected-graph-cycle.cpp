class Solution {
  public:
    bool solve(vector<vector<int>>& adj, vector<int>& flag , int i,int parent){
        
        flag[i] = true;
        
        for(auto it: adj[i]){
            if(!flag[it])
                {if(solve(adj,flag,it,i)) return true;}
            else if(it != parent) {return true;}
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> flag(V,false);
        
        for(int i=0;i<V;i++){
            if(!flag[i]){
                if(solve(adj,flag,i,-1)) return true;
            }
        }
        
        return false;
        
    }
};