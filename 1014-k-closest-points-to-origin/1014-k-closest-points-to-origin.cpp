class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,pair<int,int>>> pq; // 
        for(auto it:points){
            int x = it[0];
            int y = it[1];
            float dist = sqrt(x*x+y*y);
            if(pq.size()==k){
                if(pq.top().first > dist){
                    pq.pop();
                    pq.push({dist,{x,y}});
                }
            }
            else{
                pq.push({dist,{x,y}});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};