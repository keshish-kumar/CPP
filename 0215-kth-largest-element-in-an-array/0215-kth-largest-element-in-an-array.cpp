class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int it:nums){
            if(pq.size()==k){
                if(pq.top()<it){
                    pq.pop();
                    pq.push(it);
                }
            }
            else{
                pq.push(it);
            }
        }
        return pq.top();
    }
};