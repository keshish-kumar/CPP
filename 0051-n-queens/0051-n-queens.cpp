class Solution {
public:
    
    
    bool issafe(int row, int col, vector<string> board, int n){
        int r = row;
        int c = col;
        // we have to check in all the 8 direction to see if there is any queen or not
        //upper diagonals
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false; 
            row--;col--;
        }
        
        // lower diagonal
        row = r;
        col = c;
        while(row<n && col>=0){
            if(board[row][col] == 'Q' ) return false;
            row++;col--;
        }
        
        //left side
        row = r;
        col = c;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        
        return true;
        
    }
    
    
    
    // This function will check whether there is any possiblity to keep the qeen in that
    void solve( int col,vector<string>& board,vector<vector<string>>& ans, int n){
        
       if(col==n)
       {
           ans.push_back(board);
           return;
       }  
        
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
        
    }
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        // first we have to make n*n grid where we can put n queens 
        // criteria for n queen problem
        // 1-> every row 1-queen , 2-> every col 1-queen, 3-> none of the queen attack each other
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        // Now we have to make loop such that each col we will satrt there
        for(int i=0;i<n;i++)
            board[i] = s;
        solve(0,board,ans,n);
        return ans;
            
        
    }
};