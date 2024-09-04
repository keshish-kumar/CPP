class Solution {
public:
    int compress(vector<char>& s) {
        string ans;
        
        int i=0;
        int index =0;
       while(i<s.size()){
           int count=0;
           char c = s[i];
           int j=i;
           while(j<s.size() && s[j]==c){
               count++;
               j++;
           }
           s[index] = c;
           index++;
           if(count>1){
               string ch = to_string(count);
               for(char it:ch){
                   s[index] =it;
                   index++;
               }
           }
           i=j;
       }
       
       return index;
    }
};