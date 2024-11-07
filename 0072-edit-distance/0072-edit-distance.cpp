class Solution {
public:

    int solve(string & word1, string & word2, int i, int j){
        if(i>=word1.size() && j>=word2.size()) return 0;
        if(i>=word1.size()) return word2.size()-j;
        if(j>=word2.size()) return word1.size()-i;

        if(word1[i]==word2[j]){
            return solve(word1,word2,i+1,j+1);
        }
        else{
            return min({solve(word1,word2,i+1,j),solve(word1,word2,i,j+1),solve(word1,word2,i+1,j+1)})+1;
        }

    }
    int minDistance(string word1, string word2) {
        // edit distance problem
    //if(word1.size()<word2.size()) return 0;
    //return solve(word1,word2,0,0);
    int n = word1.size(); int m = word2.size();
    vector<int> dp(m+1,0);
    for(int i=1;i<=m;i++){
        dp[i] = i;
    }

    for(int i=1;i<=n;i++){
        vector<int> temp(m+1,0);
        for(int j=0;j<=m;j++){
            if(j==0)temp[j] = i;
            else{
                if(word1[i-1]==word2[j-1])
                        temp[j] = dp[j-1];
                else{
                    temp[j] = min({temp[j-1],dp[j],dp[j-1]})+1;
                }
            }
        }
        dp=temp;
    }

    return dp[m];


    }
};