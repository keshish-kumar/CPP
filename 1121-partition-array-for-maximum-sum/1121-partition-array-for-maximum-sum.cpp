class Solution {
public:
    int solve(vector<int>& arr, int k, int i){
        if(i==arr.size()) return 0;
        int len =0, sum=0,maxelement = INT_MIN,ans=INT_MIN;
        for(int j=i;j<(min(static_cast<int>(arr.size()),i+k));j++){
                len++;
                maxelement = max(maxelement,arr[j]);
                sum = (len*maxelement) + solve(arr,k,j+1);
                ans = max(ans,sum);
        }
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        //return solve(arr,k,0);
        vector<int> dp(arr.size()+1,0);
        for(int i=arr.size()-1;i>=0;i--){
            int len =0, sum=0,maxelement = INT_MIN,ans=INT_MIN;
            for(int j=i;j<(min(static_cast<int>(arr.size()),i+k));j++){
                len++;
                maxelement = max(maxelement,arr[j]);
                sum = (len*maxelement) + dp[j+1];
                ans = max(ans,sum);
        }
        dp[i] = ans;
        }
        return dp[0];
    }
};