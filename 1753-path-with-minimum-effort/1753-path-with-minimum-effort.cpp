class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        dist[0][0] = 0;
        vector<int> ai = {0,1,0,-1};
        vector<int> aj = {1,0,-1,0};
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                int i = pq.top().second.first;
                int j = pq.top().second.second;
                int d = pq.top().first;
                pq.pop();
                if(i==n-1 && j==m-1) return d;
                for(int k=0;k<4;k++){
                    int ii = i+ai[k];
                    int jj = j+aj[k];
                    
                    if(ii>=0 && jj>=0 && ii<n && jj<m){
                        int new_effort = max(dist[i][j],abs(heights[i][j]-heights[ii][jj]));
                        if(dist[ii][jj]> new_effort){
                            dist[ii][jj] = new_effort;
                            pq.push({dist[ii][jj],{ii,jj}});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];

    }
};