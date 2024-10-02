class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            prefix = prefix*nums[i];
            ans= max(ans,prefix);
            //ans = max(ans,prefix);
            if(nums[i]==0) prefix=1;
        }
        int suffix = 1;
        for(int i=nums.size()-1;i>=0;i--){
            suffix *=nums[i];
            ans = max(ans,suffix);
           // ans = max(ans,suffix);
            if(nums[i]==0) suffix=1;
        }
        return ans;
    }
};