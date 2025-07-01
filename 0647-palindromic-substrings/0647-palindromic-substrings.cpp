class Solution {
public:
      bool ispalindrome(string & temp, int i, int j){
        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        
        int ans =0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j)){
                    ans++;
                    }
                }
            }
        return ans;

    }
};