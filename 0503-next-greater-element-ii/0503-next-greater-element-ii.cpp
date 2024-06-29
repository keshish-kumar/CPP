class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // here we only have to know that  we have to create a array of size(0)
        int n = nums.size();
        vector<int> temp(n*2);
        vector<int> ans(2*n,-1);
        int i=0;
        int j=0;
        while(j<temp.size()){
            temp[j] = (nums[i]);
            i++;
            if(i==n) i=0;
            j++;
        }
        stack<int> st;
        st.push(temp[temp.size()-1]);
        for(int i=temp.size()-2;i>=0;i--){
            if(temp[i]<temp[i+1]){
                ans[i]=temp[i+1];
                st.push(ans[i]);
            }
            else{
                while(!st.empty() && st.top()<=temp[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i]=st.top();
                    st.push(ans[i]);
                }
            }
        }
        vector<int> r(n);
        for(int i=0;i<n;i++){
            r[i]=ans[i];
        }
        return r;
            
    }
};