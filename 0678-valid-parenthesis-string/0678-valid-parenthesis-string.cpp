class Solution {
public:
    
    bool solve(string& s, int index, int count){
        if(count<0) return false;
        if(index == s.size()){
            return (count==0);
        }
        if(s[index]=='('){
            return solve(s,index+1,count+1);
        }
        if(s[index]==')'){
            return solve(s,index+1,count-1);
        }
        return solve(s,index+1,count+1)||solve(s,index+1,count-1)||solve(s,index+1,count);
    }
    
    bool checkValidString(string s) {
       
        //return solve(s,0,0);
        
        int countmax=0,countmin=0;
        for(auto i:s){
            if(i=='(')
            {
                countmax++;countmin++;
            }
            else if(i==')'){
                countmax--;countmin--;
            }
            else{
                countmin--;
                countmax++;
            }
            
            if(countmin<0) countmin=0;
            if(countmax<0) return false;
        }
       
        return countmin==0;
        
    }
};