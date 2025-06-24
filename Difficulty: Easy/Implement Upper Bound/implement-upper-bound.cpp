// User function Template for C++
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int low = 0;
        int high = arr.size()-1;
        int ans = arr.size();
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(arr[mid]<=target){
               
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
                
        }
        return ans;
        
    }
};
