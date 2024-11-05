class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m,0);
        int ans = 0;
        for(int i=0;i<m;i++){dp[i] = matrix[0][i]; if(dp[i]==1) ans++;}
        for(int i=1;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) continue;
                if(j==0){ans++; temp[j]=matrix[i][j];}
                else {
                    int t = min({temp[j-1],dp[j],dp[j-1]});
                    temp[j] = t+1;
                   ans += temp[j];
                }
            }
            dp= temp;
        }
        return ans;
    }
};