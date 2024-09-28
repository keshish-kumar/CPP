class Solution {
public:
    bool solve(vector<int>& nums, int index,vector<int>& dp){
        if(index>=(nums.size()-1)){
            return true;
        }
        if(dp[index]!=-1) return dp[index];
         bool flag = false;
        for(int i=1;i<=nums[index];i++){
            flag = flag||solve(nums,index+i,dp);
        }

        return dp[index]=flag;
    }
    bool canJump(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // return solve(nums,0,dp);

        // Now we do using tabulation approach.
        
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxi) return false; // it means that this index i cannot be reached fron anwere before popints
            maxi = max(maxi,i+nums[i]);
        }
        return true;
    }
};