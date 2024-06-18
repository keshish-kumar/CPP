class Solution {
public:
    void combinations(vector<int>& candidates, int target,vector<vector<int>>& ans, vector<int> temp,int n){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        // if(n==candidates.size()-1){
        //     if(target==candidates[n]){
        //         temp.push_back(candidates[n]);
        //         ans.push_back(temp);
        //         return;
        //     }
        //     else{
        //         return;
        //     }
        // }
        if(n>=candidates.size()) return;
        
        combinations(candidates,target,ans,temp,n+1);
        if(target>=candidates[n]){
            temp.push_back(candidates[n]);
            combinations(candidates,target-candidates[n],ans,temp,n);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(candidates,target,ans,temp,0);
        return ans;
    }
};