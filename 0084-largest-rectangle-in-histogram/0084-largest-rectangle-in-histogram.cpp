class Solution {
public:
    void solveLeft(vector<int>& heights, vector<int>& left){
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())left.push_back(-1);
            else{
                left.push_back(st.top());
            }
            st.push(i);
        }
    }
     void solveRight(vector<int>& heights, vector<int>& right){
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--){
            
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())right.push_back(heights.size());
            else{
                right.push_back(st.top());
            }
            st.push(i);
        }
        reverse(right.begin(),right.end());
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        solveLeft(heights,left);
        solveRight(heights,right);
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans= max(ans, (right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};