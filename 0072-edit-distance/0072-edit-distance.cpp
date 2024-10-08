class Solution {
public:
    int solve(string& word1, string&word2, int i, int j){
        if(i>=word1.size()){
            return word2.size()-j;
        }
        if(j>=word2.size()){
            return word1.size()-i;
        }

        if(word1[i]==word2[j]){
            return solve(word1,word2,i+1,j+1);
        }
        else{
            // we have to perform any one of the operation
            return 1+min(solve(word1,word2,i+1,j),min(solve(word1,word2,i,j+1),solve(word1,word2,i+1,j+1)));
        }
    }
    int minDistance(string word1, string word2) {
        // minimum no of operation reqire to convert word1 to word2
        // we can perform the following operations
        // insert,delete,replace
        //return solve(word1,word2,0,0);
        // vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        // // if(i==0 and j!=0)
        // for(int j = 1;j<=word2.size();j++) dp[0][j] = j;
        // // if(i!=0 and j==0)
        // for(int i = 1; i<=word1.size();i++) dp[i][0] = i;

        // // Now we will check in dp
        // for(int i=1;i<=word1.size();i++){
        //     for(int j=1;j<=word2.size();j++){
        //         if(word1[i-1]==word2[j-1]){
        //             dp[i][j] = dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j] = 1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        //         }
        //     }
        // }
        // return dp[word1.size()][word2.size()];

        // Now we try space optimized it

        // let word2 be our vectors size which ,means our word1 will be our rows
        vector<int> dp(word2.size()+1,0);
        for(int i=1;i<=word2.size();i++) dp[i] = i;
        for(int i=1;i<=word1.size();i++){
            vector<int> temp(word2.size()+1,0);
            temp[0] = i;
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    temp[j] = dp[j-1];
                }
                else{
                    temp[j] = 1+min(dp[j-1],min(dp[j],temp[j-1]));
                }
            }
            dp=temp;
        }
        return dp[word2.size()];
    }
};