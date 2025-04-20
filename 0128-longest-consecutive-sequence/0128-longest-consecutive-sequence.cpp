class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        for(auto it:st){
            
            int temp = 1;
            if(st.find(it-1)==st.end()){
                int el = it;
                while(st.find(++el)!=st.end()){
                    temp++;
                }
            }
            ans = max(ans,temp);

        }
        return ans;
    }
};