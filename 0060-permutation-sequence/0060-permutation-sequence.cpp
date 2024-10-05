class Solution {
public:
    void solve(string &s, int&k,int index,bool&flag,string& ans){
        if(index>=s.size()){
            k--;
            if(k==0) { flag =  true; ans = s;}
            return;
        }
        if(flag==true) return;
        for(int i=index;i<s.size();i++){
            swap(s[i],s[index]);
           // k=k-1;
            solve(s,k,i+1,flag,ans);
            if(flag==true) return;
            swap(s[i],s[index]);
        }
    }
    int fact(int n){
        if(n==0) return 1;
        if(n==1) return 1;
        return n*fact(n-1);
    }
    string getPermutation(int n, int k) {
        // first we need to check for each digit.
       string s = ""; // 123
       for(int i=1;i<=n;i++)
            s = s+char('0'+i);

        // now st will conatin all the string;
        string ans="";
        int temp=0;
        while(n>0){
            //first we need to check at what factorial vaalue it is coming under that
            
            for(int i=0;i<s.size();i++){
                 temp += fact(n-1);
                if(temp>=k){
                    ans=ans+s[i]; // push into answer
                    s.erase(i,1); // earse from string
                   temp = temp-fact(n-1);
                    break;
                }
            }
            n--;
        }
        return ans;
    }
};