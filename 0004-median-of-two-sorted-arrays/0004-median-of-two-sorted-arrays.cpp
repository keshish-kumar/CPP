class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> left;
        priority_queue<int,vector<int>,greater<int>> right;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                right.push(nums1[i]);
                i++;
            }
            else{
                right.push(nums2[j]);
                j++;
            }

            if((right.size()-left.size()) >1){
                left.push(right.top());
                right.pop();
            }
        }

        while(i<nums1.size()){
            right.push(nums1[i]);
            if((right.size()-left.size())>1){
                left.push(right.top());
                right.pop();
            }
            i++;
        }

        while(j<nums2.size()){
            right.push(nums2[j]);
            if((right.size()-left.size())>1){
                left.push(right.top());
                right.pop();
            }
         j++;
        }

        if((right.size()-left.size())==1){
            return right.top();
        }
        else{
            return (right.top()+left.top())/2.00;
        }
    }
};