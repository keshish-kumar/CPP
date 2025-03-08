class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // lets try using sliding window
        int i=0,j=0,ans=0;

        unordered_map<char,int> mp;
        while(j<s.size()){
            cout<<i<<" "<<j<<endl;
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]++;
            }
            else{
                while(i<j && s[i]!=s[j]){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                i++;
            }
            ans = max(ans,(int)mp.size());
            j++;
        }
        return ans;
    }
};