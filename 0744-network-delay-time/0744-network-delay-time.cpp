class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k-1});
        vector<int> dist(n,1e9);
        dist[k-1] = 0;
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                int node = pq.top().second;
                int distance = pq.top().first;
                pq.pop();
                for(auto it:adj[node]){
                    int temp = distance+it.second;
                    if(dist[it.first]>temp){
                        dist[it.first] = temp;
                        pq.push({dist[it.first],it.first});
                    }
                }
            }
        }
        int ans =0;
        for(auto it:dist){
            ans = max(ans,it);
        }
        return ans==1e9?-1:ans;
    }
};