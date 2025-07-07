// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int length = edges[i][2];
            adj[u].push_back({v,length});
            adj[v].push_back({u,length});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(V,INT_MAX);
        q.push({0,src});
        dist[src] = 0;
        while(!q.empty()){
            int node = q.top().second;
            int length = q.top().first;
            q.pop();
            for(auto it: adj[node]){
                if(dist[it.first]>length+it.second){
                    dist[it.first] = length+it.second;
                    q.push({dist[it.first],it.first});
                }
            }
        }
        return dist;
    }
};