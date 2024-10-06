class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if( nums.size()==1) return nums[0];
        int low=0,high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(mid%2==0){// check in even position
                if(mid+1<nums.size() && nums[mid]==nums[mid+1]){
                    low=mid+1;
                }
                else 
                    high = mid-1;
            }
            else{
                if(mid-1>=0 && nums[mid]==nums[mid-1]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return nums[low];
    }
};