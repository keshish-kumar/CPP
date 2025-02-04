class Solution {
public:
    int lowerbound(vector<int>& nums, int target){
        int low=0,high=nums.size()-1;
        int ans =-1;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]==target){
                ans=mid;
            }
            if(nums[mid] >= target){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int upperbound(vector<int>&nums,int target){
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                ans=mid;
            }
            if(nums[mid]<= target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        

        return {lowerbound(nums,target),upperbound(nums,target)};
    }
};