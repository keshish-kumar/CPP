class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int it:stones)
            pq.push(it);
        
        while(pq.size()>1){
            int x = pq.top();pq.pop();
            int y = pq.top();pq.pop();
            if(x != y){
                pq.push(x-y);
            }
        }

        return pq.empty()?0:pq.top();
    }
};