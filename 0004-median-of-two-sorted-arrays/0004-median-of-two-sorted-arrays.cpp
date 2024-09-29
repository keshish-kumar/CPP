class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Now we will aply binary search to it. 
        // we need to check which is samller size and apply binary search to samller vector
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n = nums1.size();
        int m = nums2.size();
        // Now apply low to 0 an high to nums1.size()-1;
        int low = 0;
        int high = n;
        while(low<=high){
            int px = (low+high)/2; // element which will be from nums1 in left slot
            int py = (n+m+1)/2-px; // elemnet which qill be from nums2 in left slot left after filling from nums1
            
            // first half 
            int x1 = (px==0)?-1e9: nums1[px-1];
            int x2 = (py==0)?-1e9: nums2[py-1];

            // second half
            int x3 = (px==n)?1e9: nums1[px];
            int x4 = (py==m)?1e9: nums2[py];

            if(x1<=x4 && x2<=x3){
                if((n+m)%2==0) return (max(x1,x2)+min(x3,x4))/2.0;
                else return max(x1,x2);
            }
            if(x1>x4) high = px-1;
            else low = px+1;
        }
        return 0;

    }
};