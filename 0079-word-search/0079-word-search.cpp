class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i, int j, string& temp,vector<vector<int>>& visited, int n){
        if(temp==word) return true;
        if(n==word.size() ) return false;
        
        
        bool left = false;
        if(i>0 && visited[i-1][j]==-1 && board[i-1][j]==word[n]){
            temp = temp+board[i-1][j];
            visited[i-1][j]=1;
            left = solve(board,word,i-1,j,temp,visited,n+1);
            temp.pop_back();
            visited[i-1][j]=-1;
        }
        bool up =false;
        if(j>0  && visited[i][j-1]==-1 && board[i][j-1]==word[n]){
            temp = temp+board[i][j-1];
            visited[i][j-1]=1;
            up = solve(board,word,i,j-1,temp,visited,n+1);
            temp.pop_back();
            visited[i][j-1]=-1;
        }
        bool down=false;
        if(i<board.size()-1  && visited[i+1][j]==-1 && board[i+1][j]==word[n]){
            temp = temp+board[i+1][j];
            visited[i+1][j]=1;
            down = solve(board,word,i+1,j,temp,visited,n+1);
            temp.pop_back();
            visited[i+1][j]=-1;
        }
        bool right=false;
        if(j<board[0].size()-1  && visited[i][j+1]==-1 && board[i][j+1]==word[n]){
            temp = temp+board[i][j+1];
            visited[i][j+1]=1;
            right = solve(board,word,i,j+1,temp,visited,n+1);
            temp.pop_back();
            visited[i][j+1]=-1;
        }
      
        return up||down||left||right;

    }
    bool exist(vector<vector<char>>& board, string word) {
        // here we have to apply dfs search to sdearch for the word in the grid
        string temp;
        temp.push_back(word[0]);
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),-1));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=1;
                    if(solve(board,word,i,j,temp,visited,1)) return true;
                    visited[i][j]=-1;
                }
            }
        }
        return false;
    }
};