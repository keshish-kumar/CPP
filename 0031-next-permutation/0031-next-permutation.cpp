class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //1->find the lement such that nums[i-1]<nums[i];
        //2-> find the lement which is just grewater than the lement nums[j-1] from right 
        // 3->swap fromt the two and reverse from index i to end of array

        int n = nums.size();
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                // we have found the pivot elemnt
                // Now look for element which is just greater tha that
                for(int j=nums.size()-1;j>=i ;j--){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
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