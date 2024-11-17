class Solution {
public:
    void solve(vector<int>& cand, int target, int index, vector<int>& temp, set<vector<int>>& ans){
        if( target==0){
            ans.insert(temp);
            return;
        }
        if(index>=cand.size()) return ;

        if(target>=cand[index]){
            temp.push_back(cand[index]);
            solve(cand,target-cand[index],index,temp,ans);
            solve(cand,target-cand[index],index+1,temp,ans);
            temp.pop_back();
        }
        solve(cand,target,index+1,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        solve(cand,target,0,temp,ans);
        vector<vector<int>> a;
        for(auto it:ans){
            a.push_back(it);
        }
        return a;
    }
};