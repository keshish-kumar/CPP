class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        vector<int> ans(nums2.size(),-1);
         for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(nums2[i]);
         }

         unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = ans[i];
        }

       ans = {};
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};