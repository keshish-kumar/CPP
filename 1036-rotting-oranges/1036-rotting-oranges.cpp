class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // we can use bfs here 
        queue<pair<int,int>> q;
        vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(),false));
        int t=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2)
                    q.push({i,j});

            }
        }
                    vector<int> ii = {1,-1,0,0};
                    vector<int> jj = {0,0,-1,1};
                    while(!q.empty()){
                        int n = q.size();
                        while(n--){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int r = row+ii[k];
                            int c = col+jj[k];
                            if(r>=0 && c>=0 && r< grid.size() && c<grid[0].size() && grid[r][c] == 1){
                                q.push({r,c});
                                grid[r][c] = 0;
                            }
                        }
                        }
                         if(!q.empty()) t++;
                    }
        for(int i=0;i<grid.size();i++){
                        for(int j=0;j<grid[0].size();j++){
                            if(grid[i][j] == 1) return -1;
                        }
                    }
                   
        return t;
    }
};