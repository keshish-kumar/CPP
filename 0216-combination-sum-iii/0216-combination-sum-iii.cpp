class Solution {
public:
    void solve(vector<int>& t, int index, int k, int n, vector<int>& temp, vector<vector<int>>& ans){
        if(n==0 && temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<t.size();i++){
            if(n>=t[i]){
                temp.push_back(t[i]);
                solve(t,i+1,k,n-t[i],temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        solve(t,0,k,n,temp,ans);
        return ans;
    }
};