class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int level=1;
        while(!q.empty()){
            int size = q.size();
           
            while(size--){
                int i= q.front().first;
                int j = q.front().second;
                q.pop();
                vector<int> ai={0,1,1,1,0,-1,-1,-1};
                vector<int> aj={1,1,0,-1,-1,-1,0,1};
                if(i==n-1 && j==m-1) return level;
                
                for(int k=0;k<8;k++){
                    int ii=i+ai[k];
                    int jj=j+aj[k];
                    if(ii>=0 && jj>=0 && ii<n && jj<m && grid[ii][jj]==0){
                            q.push({ii,jj});
                            grid[ii][jj]=1;
                            
                    }
                } 
            }
             level++;
        }
        return -1;
    }
};