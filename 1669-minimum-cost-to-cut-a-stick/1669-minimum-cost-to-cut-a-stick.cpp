class Solution {
public:
    int solve( vector<int>& cuts, int i, int j,vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<=j;k++){

            int temp = cuts[j+1]-cuts[i-1]+solve(cuts,i,k-1,dp)+solve(cuts,k+1,j,dp);

            mini = min(mini,temp);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(cuts,1,cuts.size()-2,dp);
    }
};