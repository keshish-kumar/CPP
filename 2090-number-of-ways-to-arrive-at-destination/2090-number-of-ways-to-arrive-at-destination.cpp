class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<long long,long long>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<long long> dist(n,LONG_MAX);
        vector<long long> ways(n,0);
        ways[0]=1;
        int mod = 1e9+7;
      
        dist[0]=0;
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                int node=pq.top().second;
                long long cost=pq.top().first;
                pq.pop();
                for(auto it:adj[node]){
                    long long temp = (cost+it.second);
                    if(dist[it.first]==temp){ways[it.first] = (ways[it.first]%mod+ways[node]%mod)%mod;}
                    else if(dist[it.first]>temp){
                        dist[it.first]=temp;
                        ways[it.first]=ways[node]%mod;
                        pq.push({dist[it.first],it.first});
                    }

                }
            }
        }

        return ways[n-1]%mod;

    }
};