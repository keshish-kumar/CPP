class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            
                while(!st.empty() && st.top().first<temperatures[i]){
                    int t = st.top().second;
                    st.pop();
                    ans[t] = i-t;
                }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};