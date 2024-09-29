class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
       
         int   index1=n/2;
          int   index2=index1-1;
        
        int i=0,j=0;
        int n1=0,n2=0;
        int count=0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(count==index1) n1 = nums1[i];
                if(count==index2) n2 = nums1[i];
                i++;
            }
            else{
                if(count==index1) n1 = nums2[j]; 
                if(count==index2) n2 = nums2[j];
                j++;
            }
            count++;
        }
        while(i<nums1.size()){
            if(count==index1) n1 = nums1[i];
                if(count==index2) n2 = nums1[i];
                i++;
            count++;
        }
        while(j<nums2.size()){
            if(count==index1) n1 = nums2[j];
                if(count==index2) n2 = nums2[j];
                j++;
            count++;
        }

        if(n%2!=0) return n1;
        else return double(n1+n2)/2;
    }
};