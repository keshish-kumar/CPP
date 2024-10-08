class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the right element which is just grater tha n than curr element than reverse elements after the curr pointer till last 
        for(int i=nums.size()-2;i>=0;i--){
           int left = 1e9;
            for(int j=nums.size()-1;j>i;j--){
                if(nums[j]>nums[i] ){
                    if(left==1e9) left=j;
                    else{
                        if(nums[left]>nums[j])
                            left=j;
                    }
                }
            }
            if(left!=1e9){
                swap(nums[i],nums[left]);
                // reverse the lements after i,
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
        }

        reverse(nums.begin(),nums.end());

    }
};