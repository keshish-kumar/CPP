class Solution {
public:

    bool solve(vector<vector<char>>& board, string & word, int i, int j, int index,vector<vector<int>>& visited){
        if(index==word.size()) return true;
        vector<int> ii = {1,0,-1,0};
        vector<int> jj = {0,1,0,-1};
        for(int k=0;k<4;k++){
            int r= i+ii[k];
            int c = j+jj[k];
            if(r>=0 && c>=0 && r<board.size() && c<board[0].size()&& visited[r][c]==-1 && board[r][c] == word[index]){
                visited[r][c] = 1;
                if(solve(board,word,r,c,index+1,visited)) return true;
                visited[r][c] = -1;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> visited(n,vector<int>(m,-1));
                    visited[i][j] = 1;
                    if(solve(board,word,i,j,1,visited)) return true;
                }
            }
        }
        return false;
    }
};