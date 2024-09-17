class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            ans = max(ans,n);
            for(int j=i+1;j<nums.size();j++){
                
                n= n*nums[j];
                ans = max(ans,n);
            }

        }
        return ans;
    }
};