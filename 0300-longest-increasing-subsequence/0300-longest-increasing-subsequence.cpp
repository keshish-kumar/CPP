class Solution {
public:
    int solve(vector<int>& nums, int index, int prev , vector<vector<int>>& dp){
        if(index==nums.size()) return 0;
        
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int take =0;
        if(prev==-1 || nums[prev]<nums[index]){
            take =  1+ solve(nums,index+1,index,dp);
        }
        int nottake = solve(nums,index+1,prev,dp);
        
        return dp[index][prev+1] = max(take,nottake);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        
        // vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return solve(nums,0,-1,dp);
        
//         vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        
//         // vector<int> dp(nums.size()+1,0);
        
//         for(int index=nums.size()-1;index>=0;index--){
//             // vector<int> temp(nusms.size(),0);
//             for(int prev=index-1;prev>=-1;prev--){
//                 int take = 0;
//                if(prev==-1 || nums[prev]<nums[index]){
//                     take =  1+ dp[index+1][index+1];
//                     }
//                int nottake = dp[index+1][prev+1];
        
//                  dp[index][prev+1] = max(take,nottake);
//             }
//         }
//         return dp[0][0];
        
        
        // Binary search 
        
        // vector<int> temp;
        // temp.push_back(nums[0]);
        // for(int i=1;i<nums.size();i++){
        //     if(temp.back()<nums[i])
        //             temp.push_back(nums[i]);
        //     else{
        //         int index = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
        //         temp[index] = nums[i];
        //     }
        // }
        // return temp.size();

        // this is other type of tabulation approach
        
        vector<int> temp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            int maxi = temp[i];
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] ){
                    if(maxi<(temp[j]+temp[i]))
                        maxi = temp[j]+temp[i];
                }
            }
            temp[i] = maxi;
        }
       return *max_element(temp.begin(),temp.end());
    }
};