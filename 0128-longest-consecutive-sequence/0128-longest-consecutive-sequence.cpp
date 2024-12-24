class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
            st.insert(nums[i]);
        int ans = 0;
        for(auto it:st){
            int x=it;
            int temp=1;
            if(st.find(x-1)==st.end()){
                while(st.find(++x)!=st.end()) temp++;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};