class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // as it is given we can only flip 0's
        // we will run sliding winow in this.
        int i=0,j=0,temp=k,ans=0;
        while(j<nums.size()){
            
          
            if(nums[j]==0 ){
            if(temp>0){
                temp--;
            }
            else {
                while(i<j && nums[i]!=0){
                    i++;
                }
                i++;
                
            }
        }
        ans = max(ans,(j-i+1));
        cout<<i<<" "<<j<<endl;
            j++;
        }
        return ans;
    }
};