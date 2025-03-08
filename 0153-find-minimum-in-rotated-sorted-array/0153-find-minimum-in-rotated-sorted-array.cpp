class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans = -1;
        while(low<high){
            int mid = (low+high)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return nums[high];
    }
};