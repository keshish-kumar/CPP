class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Now I will use dijkstras to solve this question.
        
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q; // one is to store distance and other is to store the index
        vector<vector<int>> distance(n,vector< int>(m,1e9));
        q.push({1,{0,0}});
        distance[0][0]=1;
        vector<int> ai = {0,1,1,1,0,-1,-1,-1};
        vector<int> aj = {1,1,0,-1,-1,-1,0,1};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i= q.top().second.first;
                int j = q.top().second.second;
                int dist = q.top().first;
                q.pop();
                if(i==n-1 && j==m-1) return dist;
                for(int k=0;k<8;k++){
                    int ii=i+ai[k];
                    int jj=j+aj[k];
                    if(ii>=0 && jj>=0 && ii<n && jj<m && grid[ii][jj]==0){
                         if(distance[ii][jj]>(dist+1)){
                            distance[ii][jj] = dist+1;
                            q.push({distance[ii][jj],{ii,jj}});
                         }
                         grid[ii][jj]=1;
                    }
                }
            }
        }
        return -1;
    }
};