class Solution {
public:

    static bool comp(const pair<int,int>& a, const pair<int,int>& b){
        return a.first>b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end(),comp);
        stack<int> st;
        
        for(int i=0;i<position.size();i++){
            double t = ceil((double)(target - v[i].first) / v[i].second);

            if(st.empty() || st.top()<t){
                st.push(t);
            }

        }
        return st.size();
    }
};