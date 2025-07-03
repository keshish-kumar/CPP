class Solution {
public:

    int solve(string & text1, string & text2, int i , int j){
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }

        //if both the charcter mathes
        if(text1[i] == text2[j]){
            return 1+solve(text1,text2,i+1,j+1);
        }
        else{
            return max(solve(text1,text2,i+1,j) , solve(text1,text2,i,j+1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        //return solve(text1,text2,0,0);
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));

        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};