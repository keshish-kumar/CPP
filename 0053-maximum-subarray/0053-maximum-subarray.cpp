class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int ans=-1e9;
        
        int i=0;
        int sum=0;
        while(i<nums.size()){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
            i++;
        }
        return ans;
    }
};