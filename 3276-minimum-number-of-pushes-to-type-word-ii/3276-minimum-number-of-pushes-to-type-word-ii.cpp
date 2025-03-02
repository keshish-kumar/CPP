class Solution {
public:
    int minimumPushes(string word) {
         map<char,int> mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        // Now we will see how many letter we can type in one count it can be from 2 to 9 that is 8 letters than netx 8 letter to 2 type than next 8 letter to 3 type simmilalry we will look into this
        
        vector<int> v;
        for(auto it:mp){
            v.push_back(it.second);
        }

       sort(v.begin(),v.end(),greater<int>());
        int ans = 0;
        int typed = 1;
        for(int i=0;i<v.size();){
            int j=1;
            while(i<v.size() && j<=8){
                ans += v[i]*typed;
                j++;
                i++;
            }
            typed++;
        }

        return ans;
    }
};