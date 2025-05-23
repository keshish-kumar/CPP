class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n,1);
        vector<int> count(n,1);
       
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
             if(nums[j]<nums[i]){
               if(temp[j]+1 == temp[i]){
                    count[i]+=count[j];
               }
               else if(temp[j]+1 > temp[i]){
                    temp[i] = temp[j]+1;
                    count[i] = count[j];
               }  
            }
            }
           
        }
        int ans=0;
        int maxi = *max_element(temp.begin(),temp.end());

        for(int i=0;i<n;i++){
            //cout<<index[i]<<" ";
            if(temp[i]==maxi)
                ans+=count[i];
        }


        return ans;
    }
};