class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // Here we have to find next greater element of each element of nums1 in nums2
        vector<int> ans(nums1.size());
        stack<int> st;
        
        vector<int> temp(nums2.size(),-1);
        st.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2;i>=0;i--){
            // Now we have to check for this elemnt in nums2 which is greater elemnt
            // we will take stack for this and check again
            if(nums2[i]<nums2[i+1]) {temp[i]=nums2[i+1]; st.push(temp[i]);}
            else if(!st.empty()) {
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(!st.empty()){
                    temp[i]=st.top();
                }
            }
        }
        
        for(int i=0;i<nums1.size();i++){
            int j=0;
            while(j<nums2.size() ){
                if(nums1[i]==nums2[j]){
                    ans[i] = temp[j];
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};