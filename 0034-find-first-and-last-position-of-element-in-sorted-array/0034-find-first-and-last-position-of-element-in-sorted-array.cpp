class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Here we are given sorted repeated array and we need to find th first and last position of occurance of that element

        int low=0,high=nums.size()-1;
        int ans1=-1,ans2=-1;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]==target){
                int i=mid,j=mid;
                while(i>=0 && nums[i]==target){
                    ans1 = i;
                    i--;
                }
                while(j<nums.size() && nums[j]==target){
                    ans2=j;
                    j++;
                }
                return {ans1,ans2};
            }

            if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {ans1,ans2};
    }
};