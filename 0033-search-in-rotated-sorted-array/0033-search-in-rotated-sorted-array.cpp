class Solution {
public:
    int search(vector<int>& arr, int target) {
        // we will sperate both the array and check in that.
        // we will search for lower_bound of the array
        int low = 0,high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target) return mid;
           // check if left side is sorted
            if(arr[mid]>=arr[low]){
                if(arr[low]<=target && arr[mid]>target ){
                    high=mid-1;
                }
                else{
                   low = mid+1;
                }
            }
            else{ // right side sorted array
                if(arr[mid]<=target && arr[high]>=target){
                   low = mid+1;
                }
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};