class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> ans;
        queue<vector<int>> st;
        int i=1;
        st.push(intervals[0]);
        while(i<intervals.size()){

            while(i<intervals.size() && st.back()[1]>=intervals[i][0]){
                st.back()[1] = max(st.back()[1],intervals[i][1]);
                i++;
            }
            if(i<intervals.size())
                st.push(intervals[i]);
            i++;
        }
        while(!st.empty()){
            ans.push_back(st.front());
            st.pop();
        }

        return ans;
    }
};