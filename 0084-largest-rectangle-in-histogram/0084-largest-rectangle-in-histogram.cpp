class Solution {
public:
    vector<int> solveLeft(vector<int>& heights){
        vector<int> left;
        stack<int> st;

        for(int i=0;i<heights.size();i++){
            if(st.empty()){
                left.push_back(-1);
            }
            else{
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(!st.empty()) left.push_back(st.top());
                else left.push_back(-1);
            }
            st.push(i);
        }
        return left;
    }
     vector<int> solveRight(vector<int>& heights){
        vector<int> right;
        stack<int> st;
        int n = heights.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                right.push_back(n);
            }
            else{
                while(!st.empty() && heights[st.top()] > heights[i])
                    st.pop();
                if(!st.empty()) right.push_back(st.top());
                else right.push_back(n);
            }
            st.push(i);
        }
        reverse(right.begin(),right.end());
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = solveLeft(heights);
        vector<int> right = solveRight(heights);
        int ans =0;
        for(int i=0;i<heights.size();i++){
            ans = max(ans, (right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};