class Solution {
  public:
    bool solve(vector<vector<int>>& adj, int i, int parent,vector<bool>& flag){
        
        flag[i] = true;
        for(auto it:adj[i]){
            if(!flag[it] ){
                if(solve(adj,it,i,flag)) return true;
            }
            else if(it != parent){
                return true;
            }
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
        vector<bool> flag(V,false);
        for(int i=0;i<V;i++){
            if(!flag[i])
                if(solve(adj,i,-1,flag)) return true;
        }
        return false;
    }
};