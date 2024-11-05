class Solution {
public:
    vector<int> leftvertex(vector<int>& temp){
        vector<int> ans;
        stack<int> st;
        st.push(0);
        ans.push_back(-1);
        for(int i=1;i<temp.size();i++){

            while(!st.empty() && temp[st.top()]>=temp[i]){
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(i);
        }

        return ans;
    }

    vector<int> rightvertex(vector<int>& temp){
        int n= temp.size();
        vector<int> ans;
        stack<int> st;
        st.push(n-1);
        ans.push_back(n);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && temp[st.top()]>temp[i]){
                st.pop();
            }
            if(st.empty()) ans.push_back(n);
            else ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    int solve(vector<int>& temp){
        vector<int> left = leftvertex(temp);
        vector<int> right = rightvertex(temp);
        int ans =0;
        for(int i=0;i<temp.size();i++){
            int t = right[i]-left[i]-1;
            ans = max(ans,temp[i]*t);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Here we need to find maimum area in rectangle
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<int> temp(matrix[0].size(),0);
        int ans =0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0') temp[j]=0;
                else{
                    temp[j] += 1;
                }
            }
            ans = max(ans,solve(temp));
        }
        return ans;
    }
};