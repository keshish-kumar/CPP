class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans  = 0;
        for(int i=0;i<nums.size();i++){
            int count=1;
            int n = nums[i]+1;
            while(mp.find(n)!=mp.end()){
                count++;
               //mp[n]--;
                mp.erase(n);
                n+=1;

            }
            // now we also have to check for if its previous lement how many are present
            n = nums[i]-1;
            while(mp.find(n)!=mp.end()){
                count++;
                mp.erase(n);
                n-=1;
            }
            mp.erase(nums[i]);
            ans = max(ans,count);
        }
        return ans;
    }
};