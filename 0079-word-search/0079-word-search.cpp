class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j, string & word, int index,vector<vector<bool>>& flag){
        if(index >= word.size()) return true;
        bool up = false;
        if((i-1)>=0 && board[i-1][j]==word[index] && flag[i-1][j] == false){
            flag[i-1][j] = true;
            up = solve(board,i-1,j,word,index+1,flag);
            flag[i-1][j] = false;
        }
        bool down = false;
        if((i+1)<board.size() && board[i+1][j] == word[index] && flag[i+1][j] == false){
            flag[i+1][j] = true;
            down = solve(board,i+1,j,word,index+1,flag);
            flag[i+1][j] = false;
        }

        bool left = false;
        if((j-1)>=0 && board[i][j-1] == word[index] && flag[i][j-1] == false){
            flag[i][j-1] = true;
            left = solve(board,i,j-1,word,index+1,flag);
            flag[i][j-1] = false;

        }
        bool right = false;
        if((j+1)<board[0].size() && board[i][j+1] == word[index] && flag[i][j+1] == false){
            flag[i][j+1] = true;
            right = solve(board,i,j+1,word,index+1,flag);
            flag[i][j+1] = false;
        }

        return up||down||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> flag(board.size() , vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    flag[i][j] = true;
                    if(solve(board,i,j,word,1,flag)) return true;
                    flag[i][j] = false;
                }
            }
        }
        return false;
    }
};