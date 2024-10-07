class Solution {
public:
    vector<string> v;
    void solve(string & s, set<string>& st,string ans,int index){
        if(index>=s.size()){
            ans.pop_back();
            v.push_back(ans);
            return;
        }
        string curr = ans;
        for(int i=index;i<s.size();i++){
            // if word found in set than insert into string and serach another word from next i+1;
            if(st.find(s.substr(index,(i-index+1)))!=st.end()){
                ans += s.substr(index,(i-index+1))+" ";
                solve(s,st,ans,i+1);
                ans = curr;
            }
            // check for other possiblities like word or words
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(string it:wordDict){ // Here we will keep all the words in set so that we can search for it
        st.insert(it);
    }

    string ans="";
    solve(s,st,ans,0); // 0, 0, is starting index of word and j is end index of word
    return v;
    }
};