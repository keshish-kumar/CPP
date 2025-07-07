class Solution {
  public:
    bool solve(vector<vector<int>>& adj, vector<bool>& flag, int i,vector<int>& path){
        
        flag[i] = true;
        path[i] = 1;
        for(auto it:adj[i]){
            if(!flag[it] && solve(adj,flag,it,path)) return true;
            else if(path[it]==1) return true;
        }
        
        path[i] = 0;
        return false;
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        // first using DFS
        vector<bool> flag(V,false);
        vector<int> path(V,0);
        for(int i=0;i<V;i++)
            if(!flag[i] && solve(adj,flag,i,path)) return true;
        return false;
    }
};