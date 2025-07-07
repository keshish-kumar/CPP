class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> ans;
        vector<int> dist(adj.size(),INT_MAX);
        queue<pair<int,int>> q;
        dist[src] = 0;
        q.push({src,0});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int node = q.front().first;
                int length = q.front().second;
                q.pop();
                for(auto it:adj[node]){
                    
                    if(dist[it]==INT_MAX){
                        dist[it] = length+1;
                        q.push({it,length+1});
                    }
                    else if(dist[it]>length+1) dist[it]=length+1;
                }
            }
        }
        for(int i=0;i<adj.size();i++) if(dist[i]==INT_MAX) dist[i]=-1;
        return dist;
    }
};