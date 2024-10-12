class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
         // we have to find the boundary index of bothh left and right till were whats its max indx it can reach +1;
         int n = height.size();
        vector<int> left;
        left.push_back(-1);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(st.empty()) {left.push_back(-1);st.push(i);}
            else{
                left.push_back(st.top());
                st.push(i);
            }
        }

        vector<int> right;
        while(!st.empty()) st.pop();
        right.push_back(n);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && height[st.top()]>height[i]){
                st.pop();
            }
            if(st.empty()){right.push_back(n);st.push(i);}
            else{
                right.push_back(st.top());
                st.push(i);
            }
        }

        reverse(right.begin(),right.end());

        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i]-left[i]-1)*height[i]);
        }
        return ans;
    }
};