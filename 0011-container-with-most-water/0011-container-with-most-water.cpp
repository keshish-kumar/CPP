class Solution {
public:
    void SolveLeft(vector<int>& height, vector<int>& left){
        stack<int> st;

        for(int i=0;i<height.size();i++){
            if(st.empty()){
                st.push(i);
                left.push_back(i);
            }
            else{
                while(!st.empty() && height[st.top()] < height[i]){
                    st.pop();
                }
                if(!st.empty()) left.push_back(st.top());
                else{ left.push_back(0);} 
                st.push(i);
            }
            
        }

    }
    void SolveRight(vector<int>& height, vector<int>& right){
        stack<int> st;

        for(int i=height.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                right.push_back(i);
            }
            else{
                while(!st.empty() && height[st.top()] < height[i]){
                    st.pop();
                }
                if(!st.empty()) right.push_back(st.top());
                else right.push_back(height.size()-1);
                st.push(i);
            }
            
        }
        reverse(right.begin(),right.end());
        
    }
    int maxArea(vector<int>& height) {
       int ans =0;
       int i=0,j=height.size()-1;
       while(i<j){
            ans = max(ans,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
       }
       return ans;
    }
};