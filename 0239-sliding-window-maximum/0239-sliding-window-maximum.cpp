class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int i=0,j=0;
        while(j<nums.size()){
            while(!q.empty() && q.back()<nums[j]){ // this will check that samller element should not be i front 
                q.pop_back();
            }
            q.push_back(nums[j]); // push the current elemnt into q;
            if((j-i+1)==k){
                ans.push_back(q.front());
                if(nums[i]==q.front()) q.pop_front();
                i++;
            }
            j++;

        }
        return ans;
        
    }
};