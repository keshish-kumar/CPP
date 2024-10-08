class Solution {
public:
    int solve(string & text1, string &text2, int i, int j){
        if(i>=text1.size() || j>=text2.size()) return 0;

        // element mathced
        int ans = -1e9;
        if(text1[i]==text2[j]){
            return  1+solve(text1,text2,i+1,j+1);
        }
        
        return max(solve(text1,text2,i,j+1),solve(text1,text2,i+1,j));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        //return solve(text1,text2,0,0);

        // Now we will try doing it using 2d dp
        //  vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // for(int i=1;i<=text1.size();i++){
        //     for(int j=1;j<=text2.size();j++){
        //         // if j=1 and i=1 means 1 elemt is prsent in text2 and i element present in text1
        //         if(text1[i-1]==text2[j-1]){
        //             dp[i][j] = 1+dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }

        // return dp[text1.size()][text2.size()];

        // Now we will try using sinle dp
        vector<int> dp(text2.size()+1,0);
        for(int i=1;i<=text1.size();i++){
            vector<int> temp(text2.size()+1,0);
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    temp[j] = 1+temp[j-1];
                }
                else{
                    temp[j] = max(dp[j],temp[j-1]);
                }
            }
            dp=temp;
        }
        return dp[text2.size()];
    }
};