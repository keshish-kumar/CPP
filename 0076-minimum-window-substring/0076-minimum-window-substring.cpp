class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        map<char,int> mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
         
        int i=0,j=0,count=t.size(),ans1=1e9;string ans=s;
        int starti=0;

        while(i<s.size()){
            
            if(mp[s[i]]>0) count--;
            mp[s[i]]--;


           while(count==0){
            if(ans1>(i-j+1)){
                ans1 = (i-j+1);
                starti = j;
            }
            mp[s[j]]++;

            if(mp[s[j]]>0) count++;
            j++;
           }
           i++;
        }
        return ans1==1e9?"":s.substr(starti,ans1);

    }
};