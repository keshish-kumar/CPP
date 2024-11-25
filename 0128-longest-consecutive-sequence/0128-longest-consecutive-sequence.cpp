class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        int ans =0;
        for(auto it: st){
            int x = it;
            int count = 1 ;
            if(st.find(x-1)==st.end()){ // it means that sequence is starting form here
                while(st.find(x+1)!=st.end()){
                    count++;
                    x=x+1;
                }
                ans = max(ans,count);
            }
        }

        return ans;

    }
};