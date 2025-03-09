class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans((int)nums.size(),0);
        int count =0;
        int prod = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count++;
            else{
                prod *= nums[i];
            }
        }
        if(count==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    ans[i] = prod;
                }
            }
        }
        else if(count == 0){
            for(int i=0;i<nums.size();i++){
                ans[i] = prod/nums[i];
            }
        }
        return ans;
    }
};