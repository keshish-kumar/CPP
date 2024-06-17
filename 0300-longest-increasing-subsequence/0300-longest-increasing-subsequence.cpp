class Solution {
public:
    int subsequence(vector<int>& nums , int n ,int prev, vector<vector<int>>& dp){
        
        if(n==nums.size()) return 0;
        if(dp[n][prev+1]!= -1) return dp[n][prev+1];
        int included = 0;
        int notincluded =  subsequence(nums,n+1,prev,dp);
        
        if(prev == -1 || nums[n] > nums[prev]){
            
            included = 1 + subsequence(nums,n+1,n,dp);
            
        }
        
        
            return dp[n][prev+1] = max(included,notincluded);
        
        
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         return subsequence(nums,0,-1,dp);
        
//         vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
//         for(int ind = n-1; ind>=0 ; ind--){
//             for(int prev = ind-1;prev >=-1; prev--){
//                 int len = dp[ind+1][prev+1];
//                 if(prev == -1 || nums[ind]>nums[prev]){
//                     len = max(len,1+dp[ind+1][ind+1]);  // ?? why [inde+1] in prev place it should be only index
//                 }
//                 dp[ind][prev+1] = len;
//             }
//         }
//         return dp[0][0];
        
         vector<int> dp(n+1,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j = 0 ; j<i;j++){
                if(arr[j] < arr[i]){
                    dp[i] = max(1+dp[j] , dp[i]);
                }
            }
            maxi = max(dp[i],maxi);
        }
        return maxi;
    }
};