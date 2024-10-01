class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        int ans =1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                i++;
                ans++;
                nums[i] = nums[j];
            }
        }
        return  ans;
    }
};