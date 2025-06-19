class Solution {
public:
    void solve(vector<int>& cand, set<vector<int>>& st, vector<int> temp,
               int target, int index) {
        if (target == 0) {
            st.insert(temp);
            return;
        }
        if (index >= cand.size())
            return;

        if ((target - cand[index]) >= 0) {
            temp.push_back(cand[index]);
            solve(cand, st, temp, target - cand[index], index+1);
            temp.pop_back();
        }
        solve(cand, st, temp, target, index + 1);
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        set<vector<int>> st;
        vector<int> temp;
        solve(cand,st,temp,target,0);
        vector<vector<int>> ans;
        for(vector<int> it:st)
            ans.push_back(it);
        return ans;
    }
};