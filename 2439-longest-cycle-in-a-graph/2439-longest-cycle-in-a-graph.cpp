class Solution {
public:
    void solve(vector<vector<int>>&adj, vector<int>& visited, vector<int>& path, int i ,int & ans ){
        visited[i] = 1;

        for(auto it: adj[i]){
            if(visited[it]==1 && path[it]!=0){
                ans = max(ans,path[i]-path[it]+1);
            }
            if(visited[it]==0){
                path[it] = path[i]+1;
                solve(adj,visited,path,it,ans);
                path[it] = 0;
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
             adj[i].push_back(edges[i]);
        }

        // Nowwe have to apply dfs to search for cycle int his.
        vector<int> visited(n,0);
        vector<int> path(n,0);
        int ans=-1;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                path[i] = 1;
                solve(adj,visited,path,i,ans);

                path[i] = 0;
            }
        }
        return ans;
    }
};