class Solution {
public:
    void comb(vector<int>& candidates,int target, vector<int> temp, vector<vector<int>>& ans, int n){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(n==candidates.size()) return;
        
       
        for(int i=n;i<candidates.size();i++){
            if(i>n && candidates[i]==candidates[i-1]) continue;
            
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                comb(candidates,target-candidates[i],temp,ans,i+1);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        comb(candidates,target,temp,ans,0);
        return ans;
    }
};