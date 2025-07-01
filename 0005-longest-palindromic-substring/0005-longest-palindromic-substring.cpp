class Solution {
public:
    bool ispalindrome(string & temp, int i, int j){
        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;j--;
        }
        return true;
    }
    // void solve(string & s1, string & s2, int i, int j,string temp,string & ans){

    //     if(i>=s1.size() || j>=s2.size()){
    //         if(temp.size()>ans.size() && ispalindrome(temp)) ans=temp;
    //         return;
    //     }

    //     if(s1[i] == s2[j]){
    //         temp.push_back(s1[i]);
    //         solve(s1,s2,i+1,j+1,temp,ans);
    //         temp.pop_back();
    //     }
    //         if(temp.size() > ans.size() && ispalindrome(temp)) ans = temp;
    //         temp="";
    //         solve(s1,s2,i+1,j,temp,ans);
    //         solve(s1,s2,i,j+1,temp,ans);

        
    // }
    string longestPalindrome(string s) {
        // string matching
        // string s1 = s2;
        // reverse(s2.begin(),s2.end());
        // // now check for longest common substring
        // string temp = "";
        // string ans;
        // solve(s1,s2,0,0,temp,ans);
        // return ans;
        int sp = 0;
        int len = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j)){
                    if((j-i+1)>len){
                        sp = i;
                        len = j-i+1;
                    }
                }
            }
        }
        return s.substr(sp,len);
    }
};