class Solution {
public:
     void solve(vector<int>& candidates, int target, vector<int>& temp,vector<vector<int>>& ans, int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        // we will use for loop here to avoid repeatiojion of elements.

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i-1]==candidates[i]) continue;
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                solve(candidates,target-candidates[i],temp,ans,i+1);
                temp.pop_back();
            }
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,temp,ans,0);
        return ans;
    }
};