class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        if(nums.size()==1) return 0;
        if(nums[low]>nums[low+1])
            return low;
        if( nums[high]>nums[high-1]){
            return high;
        }

        while(low<=high){
            int mid = (low+high)/2;
            int prev,next;

            if(mid-1<0) prev = -1e9;
            else prev = nums[mid-1];
            if(mid+1 > nums.size()-1) next = -1e9;
            else next = nums[mid+1];
            if((nums[mid]>prev) && nums[mid]>next){
                return mid;
            }
            // check wether incressing or decreasing
            if(nums[mid]>prev && nums[mid]<next){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return 0;
    }
};