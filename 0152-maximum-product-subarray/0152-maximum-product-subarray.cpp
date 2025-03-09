class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -1e9;
        int prod = 1;
        for(int i=0;i<nums.size();i++){
            prod *=nums[i];
            ans = max(ans,prod);
            ans = max(ans,nums[i]);
        }
        prod = 1;
        for(int i=nums.size()-1;i>=0 ; i--){
            prod *= nums[i];
            ans = max(ans,prod);
            ans = max(ans,nums[i]);
        }
        return ans;
    }
};