class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low = 0,high = nums1.size();
        int n = nums1.size();
        int m = nums2.size();
        
        while(low<=high){
           int px = (low+high)/2; // element which will be from num1 in left slot
           int py = (n+m+1)/2-px; // element which will be from num2 in right slot

           // first half
           int x1 = (px==0)?-1e9:nums1[px-1];
           int x2 = (py==0)?-1e9:nums2[py-1];

           // right half
           int x3 = (px==n)?1e9:nums1[px];
           int x4 = (py==m)?1e9:nums2[py];

           if(x1<=x4 && x2<=x3){
            if((n+m)%2==0) return (max(x1,x2)+min(x3,x4))/2.0;
            else return max(x1,x2);
           }

           if(x1>x4){
            high = px-1;
           }
           else
            low = px+1;

        }

        return 0;
    }
};