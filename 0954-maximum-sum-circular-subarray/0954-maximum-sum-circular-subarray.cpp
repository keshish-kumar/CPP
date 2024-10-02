class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        // we created circular list type
        int sum = nums[0];
        int ans1 = nums[0];
        for(int i=1;i<nums.size();i++){
            sum = min(nums[i],sum + nums[i]);
            ans1 = min(ans1,sum);
        }
        // Now we have to find maximum
       int ans2 = nums[0];
       sum = nums[0];
       for(int i=1;i<nums.size();i++){
            sum = max(nums[i],sum+nums[i]);
            ans2 = max(ans2,sum);
       }
        total = total-ans1;

        if(ans2>0) return max(ans2,total);
        else return ans2;    
    }
};