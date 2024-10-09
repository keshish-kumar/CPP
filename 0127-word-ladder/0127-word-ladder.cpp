class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(string it:wordList)
            st.insert(it);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int count = q.front().second;
            q.pop();
            for(int i=0;i<word.size();i++){
                char ch = 'a';
                while(ch<='z'){
                    string temp=word;
                    temp[i] = ch;
                    
                    if(st.find(temp)!=st.end()){
                        if(temp==endWord) return count+1;
                        q.push({temp,count+1});
                        st.erase(temp);
                    }
                    ch++;
                }
            }
        }
        return 0;
    }
};