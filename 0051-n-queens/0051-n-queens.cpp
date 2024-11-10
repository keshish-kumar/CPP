class Solution {
public:
vector<vector<string>> temp;
bool ispossible(vector<string>& ans, int row,int col){

    // diagonal 
    int r = row,c = col;

    while(r>=0 && c>=0){
        if(ans[r][c]=='Q') return false;
        r--;c--;
    }
    
    r=row;c=col;
    while(r>=0 && c<ans.size()){
        if(ans[r][c] == 'Q') return false;
        r--;c++;
    }

    r=row;c=col;
    while(r>=0 ){
        if(ans[r][c]=='Q') return false;
        r--;
    }

    return true;

}

    void solve(vector<string>&ans, int index){
        if(index==ans.size()) {temp.push_back(ans); return; }

        for(int i=0;i<ans.size();i++){
            if(ispossible(ans,index,i)){
                ans[index][i] = 'Q';
                solve(ans,index+1);
                ans[index][i] ='.';
            }
        }
       
    }
    vector<vector<string>> solveNQueens(int n) {
        
         
        vector<string> ans(n);
        string s(n,'.');
        for(int i=0;i<n;i++){ // Here we have created temp vector wiht all . in that
            ans[i]=s;
        } 
        solve(ans,0);

        return temp;
    }
};