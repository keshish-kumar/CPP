class Solution {
public:
    int solve(string & s1, string & s2, int i , int j){
        if(i>=s1.size() && j>=s2.size()) return 0;
        if(i>=s1.size() || j>=s2.size()) return 0;

        int l1 = 0;
        if(s1[i]==s2[j]){
            l1 = 1+solve(s1,s2,i+1,j+1);
        }
        int l2 = max({solve(s1,s2,i+1,j),solve(s1,s2,i,j+1),solve(s1,s2,i+1,j+1)});

        return max(l1,l2);
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
         reverse(s.begin(),s.end());
       // return solve(s1,s,0,0);

        vector<int> dp(s.size()+1,0);
        for(int i=1;i<=s.size();i++){
            vector<int> temp(s.size()+1,0);
            for(int j=1;j<=s.size();j++){
                int l1 = 0;
                if(s1[i-1]==s[j-1]){
                     l1 = 1+dp[j-1];
                }
            int l2 = max({dp[j],temp[j-1],dp[j-1]});
            temp[j] = max(l1,l2);
            }
            dp = temp;
        }

        return dp[s.size()];
    }
};