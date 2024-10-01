class Solution {
public:
    void form(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j){
        if(i==board.size() && j==board[0].size()) return;
        visited[i][j]=1;
        vector<int> ii = {0,1,0,-1};
        vector<int> jj = {1,0,-1,0};
        for(int k=0;k<4;k++){
            if((i+ii[k])>=0 && (i+ii[k])<=(board.size()-1) && (j+jj[k])>=0 && (j+jj[k])<=(board[0].size()-1)){
                if(board[i+ii[k]][j+jj[k]]=='O' && visited[i+ii[k]][j+jj[k]]==0){
                    form(board,visited,i+ii[k],j+jj[k]);
                }
            }
    }
    }
    void solve(vector<vector<char>>& board, int i, int j,vector<vector<int>>& visited){
        if(i==board.size() && j==board[0].size()) return;
        
        vector<int> ii = {0,1,0,-1};
        vector<int> jj = {1,0,-1,0};
        for(int k=0;k<4;k++){
            if((i+ii[k])>0 && (i+ii[k])<(board.size()-1) && (j+jj[k])>0 && (j+jj[k])<(board[0].size()-1)){
                if(board[i+ii[k]][j+jj[k]]=='O' && visited[i+ii[k]][j+jj[k]]==0){
                    board[i+ii[k]][j+jj[k]]='X';
                    visited[i+ii[k]][j+jj[k]]=1;
                    solve(board,i+ii[k],j+jj[k],visited);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size()));
        // First we have to marke which points of cannot be converted to X
        for(int i=0;i<board.size();i++){
            // left col
            if(board[i][0]=='O' && visited[i][0]==0){
                // mark all the connected Os to 1 as viisted;
                form(board,visited,i,0);
            }
            // right col
            if(board[i][board[0].size()-1]=='O' && visited[i][board[0].size()-1]==0){
                
                form(board,visited,i,board[0].size()-1);
            }
        }
        
        // col
        for(int i=0;i<board[0].size();i++){
            // upper row
            if(board[0][i]=='O' && visited[0][i]==0){
                form(board,visited,0,i);
            }
            // lower row
            if(board[board.size()-1][i]=='O' && visited[board.size()-1][i]==0){
                form(board,visited,board.size()-1,i);
            }
        }

        for(int i=1;i<board.size()-1;i++){
            for(int j=1;j<board[i].size()-1;j++){
                if(board[i][j]=='O' && visited[i][j] == 0 ){
                    board[i][j]='X';
                    solve(board,i,j,visited);
                }
            }
        }

    }
};