class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Here we will use monotonic stack
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()){
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(!st.empty()){mp[nums2[i]] = st.top(); }
                else mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
        }

        // Now that in map we have stored element and their next graeter we will find the answer in nums1

        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};