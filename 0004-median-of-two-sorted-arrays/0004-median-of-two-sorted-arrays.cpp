class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size()>arr2.size()) swap(arr1,arr2);
        int x = arr1.size(), y = arr2.size();
      
        int low = 0, high =arr1.size();
        int k = (x+y)/2;
        while(low<=high){
            int mid = (low+high)/2; // no of lelemnt from arr1 in leftpart
            
            // Now we will fill the leftpart
            // we now know that mid is the number of elemt present in pargt1 from arr1
            // we can get number of element present in part1 from arr2 as k-mid;
            int x1 = (mid>0)?arr1[mid-1]:-1e9;
            int y1 = ((k-mid)>0 )?arr2[k-mid-1]:-1e9;
            
            // Now we will fill the rightpart
            int x2 = (mid<x)?arr1[mid]:1e9;
            int y2 = (k-mid<y)?arr2[k-mid]:1e9;
            
            if(x1<=y2 && y1<=x2){
                if((x+y)%2==0){
                    return (max(x1,y1)+min(x2,y2))/2.0;
                }
                else
                    return min(x2,y2);
            }
            
            if(x1>y2){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};