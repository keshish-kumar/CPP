class Solution {
public:
    void solve(vector<int>& cand, int target, int index, vector<int>& temp, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<cand.size();i++){
            if(i>index && cand[i]==cand[i-1]){
                continue;
            }
            if(target>=cand[i]){
                temp.push_back(cand[i]);
                solve(cand,target-cand[i],i+1, temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates, target, 0, temp, ans);
        return ans;
    }
};