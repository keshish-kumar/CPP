class Solution {
public:
    int solve(vector<int>& nums, int n,int prev,vector<int>& v, vector<int>& ans,vector<vector<int>>& dp){
        if(n==nums.size()){
           if( v.size()>ans.size())
                ans=v;
            return 0;
        }
        if(dp[n][prev+1]!=-1) return dp[n][prev+1];
        // pick element
        int take =0;
        if(prev==-1 || (nums[n]%nums[prev])==0){
            v.push_back(nums[n]);
             take = 1+ solve(nums,n+1,n,v,ans,dp);
            v.pop_back();
        }
        //not pick element
         int nottake = solve(nums,n+1,prev,v,ans,dp);
         return dp[n][prev+1] = max(take,nottake);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        // int n = -1;
        // vector<int> ans;
        // vector<int> v;
        // vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // solve(nums,0,-1,v,ans,dp);
        // return ans;

        vector<int> temp(nums.size(),1);
        vector<int> index(nums.size());
        index[0] = -1;
        for(int i=1;i<nums.size();i++){
            int maxi = 1;
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j])==0){
                    if(maxi < (temp[i]+temp[j])){
                        maxi = temp[i]+temp[j];
                        index[i] = j;
                    }
                }
            }
            if(maxi==1) index[i]=i;
            temp[i] = maxi;
        }
        // Now we have to the maxium and also its index to traverse back and print it

        int ind=0;
        int maxi = 1;
        
        for(int i=0;i<nums.size();i++){
            
            if(maxi< temp[i]){
                maxi = temp[i];
                ind = i;
            }
           cout<<index[i]<<" ";

        }
        cout<<endl;
        // i is the index from whic we need to print
        vector<int> ans;
        while(true){
            ans.push_back(nums[ind]);
            if(index[ind]==-1 || index[ind]==ind) break;
            ind = index[ind];

        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};