class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> right;
        stack<int> st;
        int n = nums2.size();
        st.push(n-1);
        right.push_back(n);
        int i =n-2;
        while(i>=0){
            while(!st.empty() && nums2[st.top()]<nums2[i]){
                st.pop();
            }
            if(st.empty()) right.push_back(n);
            else right.push_back(st.top());
            st.push(i);
            i--;
        }
        reverse(right.begin(),right.end());
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]]={right[i]};
        }

        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int k = mp[nums1[i]];
            if(k==n) k=-1;
            else k = nums2[k];
            ans.push_back(k);
        }
        return ans;
    }
};