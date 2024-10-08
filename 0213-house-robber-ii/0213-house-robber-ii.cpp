class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),0);
        dp[0] = 0;
        dp[1] = nums[0]; // Here we are conmsidering that we have taken the foirstr elemnt
        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-1] , nums[i-1]+dp[i-2]);
        }

        vector<int> dpt(nums.size()+1,0);
        dpt[0] = 0;
        dpt[1] = 0;
        dpt[2] = nums[1];
        for(int i=3;i<=nums.size();i++){
            dpt[i] = max(dpt[i-1] , nums[i-1]+dpt[i-2]); 
        }

        return max(dp[nums.size()-1],dpt[nums.size()]);

    }
};