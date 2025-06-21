class Solution {
public:
    void solve(vector<vector<char>>& grid, vector<vector<bool>>& flag, int row, int col){
        flag[row][col] = true;
        vector<int> i = {0,1,0,-1};
        vector<int> j = {1,0,-1,0};

        for(int k=0;k<4;k++){
            int r = row+i[k];
            int c = col+j[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == '1' && flag[r][c] == false){
                solve(grid,flag,r,c);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> flag(grid.size(),vector<bool>(grid[0].size() , false));
        int ans =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1' && flag[i][j] == false){
                    ans++;
                    solve(grid,flag,i,j);
                }
            }
        }

        return ans;

    }
};