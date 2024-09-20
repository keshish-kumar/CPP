class Solution {
public:
    int pivot(vector<int>& nums){
        int low = 0, high = nums.size()-1;
        int n = -1;
        while(low<=high){
            int mid = (low+high)/2;
           n=mid;
            if(nums[mid]<nums[high]){
                high = mid;
            }
            else{
                 
               low = mid+1;
            }
        }
        return n;
    }
    int find(vector<int>& nums, int target, int low, int high){
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            if(target>nums[mid]){
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return -1;
   }
    int search(vector<int>& nums, int target) {
        // first we have to find pivot element which will partition the array so that wqe can search and individual array

        // pivot element
        int n = pivot(nums);
        cout<<n<<endl;
        if(n==0) return find(nums,target,n,nums.size()-1);
        else{
            if(find(nums,target,0,n-1)!=-1) return   find(nums,target,0,n-1);
            else return find(nums,target,n,nums.size()-1);
        }
    }
};