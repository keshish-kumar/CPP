class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>> q; // daiistance, node, k
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        while(!q.empty()){
            int distance = q.front().first;
            int node = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            if(level>k)  continue;
            for(auto it:adj[node]){
                int d = it.second;
                if(dist[it.first] > (d+distance)){
                    dist[it.first] = d+distance;
                    if(it.first!=dst)
                        q.push({dist[it.first],{it.first,level+1}});
                }
            }
        }

        return dist[dst]==1e9?-1:dist[dst];
    }
};