class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        for(int i=nums.size()-2;i>=0 ;i--){
            int left = 1e9;
            for(int j = nums.size()-1;j>i;j--){
                if(nums[j]>nums[i]){
                    if(left==1e9) left = j;
                    else{
                        if(nums[j]<nums[left]) left = j;
                    }
                }
            }
            if(left!=1e9){
            swap(nums[i],nums[left]);
            reverse(nums.begin()+i+1,nums.end());
            return;
            }
        }
       
        reverse(nums.begin(),nums.end());
    }
};