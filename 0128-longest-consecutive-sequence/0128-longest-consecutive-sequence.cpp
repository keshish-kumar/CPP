class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
            st.insert(nums[i]);
        int ans=0;
        for(auto it: st){
            int count= 1;
            if(st.find(it-1)==st.end()){
                int n = it;
                while(st.find(++n)!=st.end()){
                    count++;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};