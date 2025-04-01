class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                while(!st.empty() && st.top()<=nums[i])
                    st.pop();
                if(!st.empty()) ans[i] = st.top();
            }
            st.push(nums[i]);
        }

        // Now the stored value we will use 
        for(int i=nums.size()-1;i>=0;i--){
             if(st.empty()){
                ans[i] = -1;
            }
            else{
                while(!st.empty() && st.top()<=nums[i])
                    st.pop();
                if(!st.empty()) ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};