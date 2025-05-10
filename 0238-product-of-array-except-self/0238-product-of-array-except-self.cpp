class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int prod = 1;
        for(int i=1;i<nums.size();i++){

            prod = prod*nums[i-1];

            ans[i] = prod;

        }
        int post = nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i] = ans[i]*post;
            post = post*nums[i];
        }
        return ans;
    }
};