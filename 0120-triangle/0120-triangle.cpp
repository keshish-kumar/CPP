class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i,int row,vector<vector<int>>& dp){
        if(row==triangle.size()) return 0;

        // we have to option either take for sam i or change to i+1
        if(dp[i][row]!=-1) return dp[i][row];
        int i1=INT_MAX;
        if((i+1) < triangle[row].size()){
            i1 = triangle[row][i+1] + solve(triangle,i+1,row+1,dp);
        }

        return  dp[i][row] = min(triangle[row][i]+solve(triangle,i,row+1,dp) , i1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle[triangle.size()-1].size(),vector<int>(triangle.size(),-1));
        return triangle[0][0] + solve(triangle,0,1,dp);



    }
};