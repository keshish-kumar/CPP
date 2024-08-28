class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1; // i is for 0, j is for 1 and k is for 2

        while(k>=j){
            if(nums[j]==1) j++;
           else if(nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
           }
           else{ // nums[j]=0
            swap(nums[i],nums[j]);
            i++;j++;
           }
        }
    }
};