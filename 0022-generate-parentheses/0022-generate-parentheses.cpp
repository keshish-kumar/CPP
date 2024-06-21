class Solution {
public:
    void generate(int open, int close, vector<string>& ans, string temp, int total){
        if(temp.size() == 2*total){
       
            ans.push_back(temp);
            return;
        }
        if(open<total){
         temp +='(';
        generate(open+1,close,ans,temp,total);
            temp.pop_back();
        }
        if( close<open ){
        temp+=')';
        generate(open,close+1,ans,temp,total);
            temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string temp="";
        generate(0,0,ans, temp,n);
        return ans;
    }
};