class Solution {
public:
    int maxProduct(vector<int>& nums) {
       // one we have to move from right and other we have to move from left
       int ans = -1e9;
       int p=1;
       for(int i=0;i<nums.size();i++){
        p *=nums[i];
        ans = max(ans,p);
        if(p==0) p=1;
       }
       p=1;
       for(int i=nums.size()-1;i>=0;i--){
        p *=nums[i];
        ans = max(ans,p);
         if(p==0) p=1;
       }
       return ans;
    }
};