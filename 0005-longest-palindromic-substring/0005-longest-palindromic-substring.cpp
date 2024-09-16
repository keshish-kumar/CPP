class Solution {
public:
    bool solve(string& s, int i, int j,vector<vector<int>>& dp){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j]; 
        if(s[i] == s[j])
            return dp[i][j] = solve(s,i+1,j-1,dp);
        else return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        
        int maxi = INT_MIN;
        int start = 0;
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if( solve(s,i,j,dp) == true ){
                    if((j-i+1)>maxi){
                        start = i;
                        maxi = (j-i+1);
                    }
                  
                }
            }
        }

        return s.substr(start,maxi);
    }
};