class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        sort(s1.begin(),s1.end());
        int n = s1.size();
        for(int i=0;i<=s2.size()-s1.size();i++){
            string s = s2.substr(i,n);
            //cout<<s<<endl;
            sort(s.begin(),s.end());
            if(s1==s) return true;
        }
        return false;
    }
};