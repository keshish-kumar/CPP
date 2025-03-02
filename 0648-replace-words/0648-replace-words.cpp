class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // first put dicitonary into set
        unordered_set<string> st;
        for(int i=0;i<dictionary.size();i++){
            st.insert(dictionary[i]);
        }

        // next traverse the sentecne into vector of string 
        string words;
        stringstream ss(sentence);
        string token;

        while(getline(ss,token,' ')){
            int j=0;
            string s;
            string temp = token;
            while(j<token.size()){
                s+= token[j];
                if(st.find(s)!=st.end()){
                    temp = s;
                    break;
                }
                j++;
            }
            words += ' '+temp;
        }
        words.erase(0,1);
    return words;
    }
};