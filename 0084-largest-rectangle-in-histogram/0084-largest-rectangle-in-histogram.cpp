class Solution {
public:
    vector<int> solveleft(vector<int>& heights){
        stack<int> st;
        vector<int> left;
        st.push(0);
        left.push_back(-1);
        int i=1;
        while(i<heights.size()){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) left.push_back(-1);
            else left.push_back(st.top());
            st.push(i);
            i++;
        }

        return left;
    }
    vector<int> solveright(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> right;
        right.push_back(n);
        st.push(n-1);
        int i = n-2;
        while(i>=0){
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()) right.push_back(n);
                else right.push_back(st.top());
                st.push(i);
                i--;
        }
        reverse(right.begin(),right.end());
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> left = solveleft(heights);
        vector<int> right = solveright(heights);
        int ans =0;
        for(int i=0;i<heights.size();i++){
            //cout<<right[i]<<" "<<endl;
            ans = max(ans,abs(right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};