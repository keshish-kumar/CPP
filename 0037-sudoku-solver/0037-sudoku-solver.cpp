class Solution {
public:

    bool ispossible(vector<vector<char>>& board, int row, int col, char c){

        for(int i=0;i<9;i++){
                if(board[i][col]==c) return false;
                if(board[row][i]==c) return false;

                // Now check for the boxes
                if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char  c='1';c<='9';c++){
                        
                        if(ispossible(board,i,j,c)){
                                board[i][j] = c;
                                if(solve(board)) return true;
                                else board[i][j]='.';
                        }
                    }
                    return false;
                }

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // This is recursion and backtracking question
        solve(board);
    }
};