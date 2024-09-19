class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
        visited[i][j]=1;

        // horizontal and vertical means it can go in our direction 
         
        if(j<(grid[0].size()-1) && visited[i][j+1]==-1 && grid[i][j+1]=='1') dfs(grid,visited,i,j+1); 
        if(j>0 && visited[i][j-1] == -1 && grid[i][j-1]=='1') dfs(grid,visited,i,j-1);
        if(i<(grid.size()-1) && visited[i+1][j]==-1 && grid[i+1][j]=='1') dfs(grid,visited,i+1,j);
        if(i>0 && visited[i-1][j]==-1 && grid[i-1][j]=='1') dfs(grid,visited,i-1,j); 
         
    }
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),-1));
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==-1 && grid[i][j]=='1'){
                    //cout<<"1"<<endl;
                    dfs(grid,visited,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};