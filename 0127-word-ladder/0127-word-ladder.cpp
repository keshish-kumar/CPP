class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(string it:wordList){
            st.insert(it);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            int n = q.front().second;
            string w = q.front().first;
            q.pop();
            for(int i=0;i<w.size();i++){
                char j = 'a';
                while(j<='z'){
                    string temp = w;
                    temp[i]=j;
                    if(st.find(temp)!=st.end()){
                        if(temp==endWord) return n+=1;
                        q.push({temp,n+1});
                        st.erase(temp);
                    }
                    
                    j++;
                }
            }
        }
        return 0;
    }
};