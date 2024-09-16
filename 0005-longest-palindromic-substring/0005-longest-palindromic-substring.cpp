class Solution {
public:
    bool solve(string& s, int i, int j){
        if(i>=j) return true;
        //if(dp[i][j]!=-1) return dp[i][j] ; vector<vector<int>>& dp
        if(s[i]==s[j])
            return solve(s,i+1,j-1);
        else return  false;
    }
    string longestPalindrome(string s) {
        
        int maxi = INT_MIN;
        int start = 0;
       // vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if( solve(s,i,j) == true ){
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