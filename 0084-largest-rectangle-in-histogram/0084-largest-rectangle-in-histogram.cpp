class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        int n = heights.size();
        stack<int> stleft;

        left.push_back(-1);
        stleft.push(0);
        for(int i=1;i<heights.size();i++){
            while( !stleft.empty() && heights[stleft.top()]>=heights[i]){
                stleft.pop();
            }
            if(stleft.empty()){
                stleft.push(i);
                left.push_back(-1);
            }
            else{
                left.push_back(stleft.top());
                stleft.push(i);
            }
        }

         stack<int> st;

        right.push_back(n);
        st.push(n-1);

        for(int i=n-2;i>=0;i--){
            while( !st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(i);
                right.push_back(n);
            }
            else{
                
                right.push_back(st.top());
                st.push(i);

            }
        }

        reverse(right.begin(),right.end());


        int ans =0;
        for(int i=0;i<n;i++){
            ans = max (ans, (right[i]-left[i]-1)*heights[i]);
            cout<<left[i]<<" "<<right[i]<<endl;
        }
        return ans;
    }
};