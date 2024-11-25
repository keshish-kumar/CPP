class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int  low =0, high = arr.size()-1;
        while(low<=high){

            int mid = low + (high - low) / 2;
            if(k<=(arr[mid]-mid-1)){
                high = mid-1;
            }
            else low =mid+1;
        }
        return k+high+1;
    }
};