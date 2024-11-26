class Solution {
public:
    vector<vector<string>> ans;
    bool ispossible(int index, int j,vector<string>& temp){
        int r = index;
        int c = j;
        while(r>=0 && c>=0){
            if(temp[r][c] == 'Q') return false;
            r--;c--;
        }

        r= index;
        c = j;
        while(r>=0 && c<temp.size()){
            if(temp[r][c]=='Q') return false;
            r--;c++;
        }

        // check for the bacj side
        r = index;
        while(r>=0){
            if(temp[r][j]=='Q') return false;
            r--;
        }

        return true;
    }
    void solve(int n , vector<string>& temp , int index){
        if(index>=n){
            ans.push_back(temp);
            return;
        }

        for(int j=0;j<n;j++){
            if(ispossible(index,j,temp)){
                temp[index][j] = 'Q';
                solve(n,temp,index+1);
                temp[index][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
         vector<string> temp(n, string(n, '.'));
        solve(n,temp,0);
        return ans;

    }
};