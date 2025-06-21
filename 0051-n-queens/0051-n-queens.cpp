class Solution {
public:
    bool isSafe(int n,vector<string>& board, int row, int col){
        // vertical cheking
        int i = row-1;
        while(i>=0){ if(board[i][col] == 'Q') return false; i--;}
        int j = col-1;
        while(j>=0){ if(board[row][j] == 'Q') return false; j--;}

        // left diagonal
        i=row-1;
        j=col-1;
        while(i>=0 && j>=0){if(board[i][j] == 'Q') return false; j--;i--;}

        // right upper diagonal
        i=row-1;
        j=col+1;
        while(i>=0 && j<n){if(board[i][j] == 'Q') return false; j++;i--;}

        return true;

    }
    void solve(int n, vector<vector<string>>& ans, vector<string>& board, int row){
        if(row>=n){
            ans.push_back(board);
            return;
        }

            for(int j=0;j<n;j++){
                if(isSafe(n,board,row,j)){
                    board[row][j] = 'Q';
                    solve(n,ans,board,row+1);
                    board[row][j] = '.';
                }
            }
    
    }
    vector<vector<string>> solveNQueens(int n) {
        // firts we have to make vector of string which have .....
        vector<vector<string>> ans;
        vector<string> board;
        string s ;
        for(int i=0;i<n;i++) s.push_back('.');
        for(int i=0;i<n;i++) board.push_back(s);

        solve(n,ans,board,0);

        return ans;
    }
};