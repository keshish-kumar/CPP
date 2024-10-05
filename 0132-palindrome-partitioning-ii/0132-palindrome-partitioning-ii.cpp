class Solution {
public:
     bool permut(int start, int end, string& s){
        if(end==start) return true;
        while(start<end){
            if(s[start++]!=s[end--]) return false;

        }
        return true;
    }
    int solve(string& s ,int n,vector<int>& dp){
        if(n>=s.size()){

            return 0;
        }
       if(dp[n]!=-1) return dp[n];
       int mini = 1e9;
        for(int i=n;i<s.size();i++){
            if(permut(n,i,s)){
                //temp.push_back(s.substr(n,(i-n+1)));
               mini = min(mini,1+solve(s,i+1,dp));
               // temp.pop_back();
            }
        }
        return dp[n]=mini;
    }
    int minCut(string s) {
        int ans =1e9;
        //vector<string> temp;
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp)-1;
        

    }
};