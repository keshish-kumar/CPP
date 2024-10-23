class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; 
        // we will make adjacency matrix which will strore path which can be visited from .
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        // Now that we have found adjacancy matrix we will apply dijkstras algorithm as weight is also given.
        pq.push({0,{src,0}}); // initially src will be zero.
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        int ans =  1e9;
        while(!pq.empty()){
                int dis = pq.top().second.second;
                int level = pq.top().first;
                int node = pq.top().second.first;
                
                pq.pop();
                if(node==dst){ ans = min(ans,dis);continue;} 
                if(level>k) continue;
                
                
                for(auto it:adj[node]){
                   
                    
                    if(level<=k && dist[it.first]>(dis+it.second)){
                        dist[it.first] = dis+it.second;
                        pq.push({level+1,{it.first,dist[it.first]}});
                    }
                }
            
        }

        return ans==1e9?-1:ans;

    }
};