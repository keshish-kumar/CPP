class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        set<int> winner;
        set<int> losser;
        map<int,int> mp; // will keep trak of key and no of time it have lost matches
        for(int i=0;i<matches.size();i++){
            mp[matches[i][1]]++;
        }
        // Now we will check if that team is poresent in map lost track
        for(auto it:mp)
            cout<<it.first<<" "<<it.second<<endl; 
        for(int i=0;i<matches.size();i++){
            if(mp.find(matches[i][0])==mp.end()){
                winner.insert(matches[i][0]);
            }
            if(mp[matches[i][1]]==1){
                losser.insert(matches[i][1]);
            }
        }
        vector<int> temp;
        for(auto it:winner){
            temp.push_back(it);
        }
        vector<int> temp1;
        for(auto it:losser){
            temp1.push_back(it);
        }
        ans.push_back(temp);
        ans.push_back(temp1);
        return ans;
    }
};