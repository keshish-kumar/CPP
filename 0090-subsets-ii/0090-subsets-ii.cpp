class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>>& st, vector<int> temp, int index){
        if(index==nums.size()){
            st.insert(temp);
            return;
        }

        // not pick
        solve(nums,st,temp,index+1);

        // pick
        temp.push_back(nums[index]);
        solve(nums,st,temp,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<int> temp;
        solve(nums,st,temp,0);

        vector<vector<int>> ans;
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};