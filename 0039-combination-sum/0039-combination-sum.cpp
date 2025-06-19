class Solution {
public:
    void solve(vector<int>& cand, vector<vector<int>>& ans, vector<int> temp, int target, int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(index>=cand.size()) return ;
        

        if((target-cand[index])>=0){
            temp.push_back(cand[index]);
            solve(cand,ans,temp,target-cand[index],index);
            temp.pop_back();
        }
        solve(cand,ans,temp,target,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(cand,ans,temp,target,0);
        return ans;
    }
};