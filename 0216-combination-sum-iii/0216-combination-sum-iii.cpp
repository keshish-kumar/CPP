class Solution {
public:
     void comb(vector<int>& candidates,int target, vector<int> temp, vector<vector<int>>& ans, int n,int k){
        if(target==0){
            if(temp.size()==k)
              ans.push_back(temp);
            return;
        }
        if(n==candidates.size()) return;
        
       
        for(int i=n;i<candidates.size();i++){
            if(i>n && candidates[i]==candidates[i-1]) continue;
            
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                comb(candidates,target-candidates[i],temp,ans,i+1,k);
                temp.pop_back(); // this should not be included in next combination as its already used here.
            }
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        for(int i=0;i<9;i++){
            candidates.push_back(i+1);
        }
         vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        comb(candidates,n,temp,ans,0,k);
        return ans;
    }
};