class Solution {
public:
    bool ispossible(vector<vector<char>>& board, int row, int col, char ch){

        for(int i=0;i<9;i++){
            // check for row
            if(board[i][col]== ch) return false;
            // check for col
            if(board[row][i] == ch) return false;
            // check for box
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;

        }
        return true;
    }

    bool solve(vector<vector<char>>& board){


        // we have to to traverse for each colum of that row and chck wether we can put numbers from 1 to 9 inn that 
        for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){ // col
            if(board[row][col]=='.'){
            for(char i='1';i<='9';i++){
                if( ispossible(board,row,col,i)){ // we will check wether we can put number i in that position
                    board[row][col] = i;
                    if(solve(board)) return true;
                    else board[row][col] = '.';
                }
               
            }
              return false; 
        }
        }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         // We are given boards in which number and . are given
         // we have to check wether number from 1to 9 can bee filled inside this or not
         // for this we will use backtracking
         solve(board); // we will start with 0 row;
    }
};