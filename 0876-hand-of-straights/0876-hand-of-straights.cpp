class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(begin(hand),end(hand));
        unordered_map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            int group = 1;
            int r = hand[i];
            while(group<groupSize && mp.find(--r) != mp.end()){
                group++;
            }

            if(group==groupSize){
                group=1;
                r=hand[i];
                while(group<groupSize){
                    mp[--r]--;
                    if(mp[r]==0) mp.erase(r);
                    group++;
                }
            }
            else
                mp[hand[i]]++;
        }
        //for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;

        return mp.empty()?true:false;
    }
};