class Solution {
public:
    bool wordPattern(string pattern, string s) {
          // first we will extract all the words from the string
          vector<string> str;
          for(int i=0;i<s.size();i++){
            int len =0;
            int j=i;
            while(  i<s.size() && s[i]!=' '){
                len++;
                i++;
            }
            str.push_back(s.substr(j,len));
          }
          for(int i=0;i<str.size();i++) cout<<str[i]<<endl;

          if(pattern.size()!= str.size()) return false;

          unordered_map<string,char> mp;
          unordered_set<char> st;

          for(int i=0;i<pattern.size();i++){

            if(mp.find(str[i])!=mp.end()){
                if(mp[str[i]] != pattern[i]) return false;
            }
            else{
                if(st.find(pattern[i])==st.end())
                    {mp[str[i]]=pattern[i];
                    st.insert(pattern[i]);}
                else return false;
            }
          }
          return true;
    }
};