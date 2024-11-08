class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(board[i][j]>='1' && board[i][j]<='9'){
                        for(int k=0;k<9;k++){
                            if(board[i][k]==board[i][j] && k!=j) return false;
                            if(board[k][j]==board[i][j] && k!=i) return false;
                            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==board[i][j] &&i!=3*(i/3)+k/3 && j!=3*(j/3)+k%3 ) return false;
                        }

                    }
                }
            }
            return true;
    }
};