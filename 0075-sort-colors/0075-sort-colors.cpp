class Solution {
public:
    void sortColors(vector<int>& nums) {
        // first approch is we keep the count of 1's 09's and 2's and modify the array accordingly
        // second method using three pointers
        int i=0,j=0,k=nums.size()-1; // i-0,j-1,k-2
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
        //return;
    }
};