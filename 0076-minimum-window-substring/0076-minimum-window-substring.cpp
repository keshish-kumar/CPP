class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(char it:t)
            mp[it]++;
        int count = t.size();
        int i=0,j=0,ans=INT_MAX;int str = -1;
        while(j<s.size()){
           
            if(mp[s[j]]>0){ // important to check before reducing it 
                count--; 
            }
            mp[s[j]]--;
            while(count==0){
               // cout<<s.substr(i,j-i+1);
                if(ans>(j-i+1)){
                    str = i;
                    ans = j-i+1;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) count++;
                i++;
            }
             j++;
        }

       
        return str==-1?"": s.substr(str,ans);
    }
};