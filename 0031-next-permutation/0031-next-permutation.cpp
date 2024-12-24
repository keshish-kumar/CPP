class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         
         // first we have to find about the pivot element
         // element fom right is. statosys arr[i-1]<arr[i]
         for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                for(int j=nums.size()-1;j>=i;j--){
                    if(nums[j]>nums[i-1]){
                        swap(nums[i-1],nums[j]);
                        break;
                    }
                }
                reverse(nums.begin()+i,nums.end());
                return;
            }
         }
         reverse(nums.begin(),nums.end());
    }
};