class Solution {
public:
    vector<vector<int>> ans;
    int timer = 1;

    void dfs(int node, int parent , vector<int>& low, vector<int>& time, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        time[node] = low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it == parent ) continue;
            if(visited[it]==0){
                dfs(it,node,low,time,adj,visited);
                low[node] = min(low[node],low[it]);
                if(low[it]>time[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }

        }
    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> low(n,0);
        vector<int> time(n,0);
        vector<int> visited(n,0);

        dfs(0,-1,low,time,adj,visited);
        return ans;

    }
};