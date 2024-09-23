class Solution {
public:
    void dfs(vector<vector<int>>& board, vector<vector<int>>& grid, int i, int j,vector<vector<int>>& visited){
        // if(i==board.size() && j==board[0].size()) return;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j]) return;
        vector<vector<int>> v{{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
        // Now we have to check all the 4 conditions
        int count=0;
            for(int k=0;k<v.size();k++){
                if((i+v[k][0])>=0 && (j+v[k][1])>=0 && (i+v[k][0])<board.size() && (j+v[k][1])<board[0].size()){
                        if(grid[i+v[k][0]][j+v[k][1]]==1) count++;
                }
            }
        if(grid[i][j] == 1){
            if(count<2 || count>3) board[i][j] = 0; 
        }
        else{
            if(count==3) board[i][j] = 1;
        }


        // Now we have to travrse all the nodes
        visited[i][j] = 1;
        for(int k=0;k<v.size();k++){
                if((i+v[k][0])>=0 && (j+v[k][1])>=0 && (i+v[k][0])<board.size() && (j+v[k][1])<board[0].size() && visited[i+v[k][0]][j+v[k][1]]==0){
                        dfs(board,grid,i+v[k][0],j+v[k][1],visited);
                }
            }

    }
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> grid = board;
        // remeber we have to make changes in board;
        // we have to check the conditions
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0)); 
        dfs(board,grid,0,0,visited);
    }
};