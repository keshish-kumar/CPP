class Solution {
public:
    bool solve(int n, int m, vector<vector<char>>& board, string & word,int p,vector<vector<int>>& visited){
        if(p>=word.size()) return true;
        vector<int> ii={0,1,0,-1};
        vector<int> jj={1,0,-1,0};
       
       
       visited[n][m] = 1;
                for(int k=0;k<4;k++){
                    int row = n+ii[k];
                    int col = m+jj[k];
                    if(row>=0 && col>=0 && row<board.size() && col<board[0].size() && visited[row][col]==0 && board[row][col]==word[p]){             
                        if(solve(row,col,board,word,p+1,visited)) return true;
                         
                    }
                }
               visited[n][m] = 0;

                return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               
                if(board[i][j] == word[0] &&  visited[i][j] == 0){
                     visited[i][j] = 1;
                    if(solve(i,j,board,word,1,visited)) return true;
                     visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};