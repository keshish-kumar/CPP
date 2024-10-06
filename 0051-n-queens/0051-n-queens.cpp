class Solution {
public:
    bool ispossible(vector<string>& temp,  int n, int row, int col){
        
        int r = row;
        int c = col;
        // left diagonal
        while(r>0 && c>0){
            if(temp[r-1][c-1]=='Q') return false;
            r--;c--;
        }

        r = row; c = col;
        // right diagonal
        while(r>0 && c<(n-1)){
            if(temp[r-1][c+1]=='Q') return false;
            r--;c++;
        }

        r =row;c=col;

        // up
        while(r>0){
            if(temp[r-1][c] == 'Q') return false;
            r--;
        }

        return true;

    }
    void solve(int n, vector<vector<string>>& ans, vector<string>& temp, int row){
        if(row == n) {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){ // this will be col
            if(ispossible(temp,n,row,i)){
                temp[row][i] = 'Q';
                solve(n,ans,temp,row+1);
                temp[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++){ // Here we have created temp vector wiht all . in that
            temp[i]=s;
        } 
        solve(n,ans,temp,0); // 0 repsents the row 
        return ans;

    }
};