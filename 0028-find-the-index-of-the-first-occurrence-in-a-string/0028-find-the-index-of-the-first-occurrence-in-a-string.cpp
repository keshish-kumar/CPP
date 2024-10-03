class Solution {
public:
    void LPS(string& needle,vector<int>& lps){
        int length = 0;
        
        for(int i=1;i<needle.size();i++){
            cout<<i<<" ";
            length = lps[i-1];
            
            while(length>0 && needle[length]!=needle[i]){
                length = lps[length-1];
            }
            if(needle[length] == needle[i]) lps[i] = length+1;
            else lps[i] = 0;
            cout<<length<<endl;
        }
    }
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(),0);
        LPS(needle,lps);
       for(int i=0;i<lps.size();i++) cout<<lps[i]<<" "; cout<<endl;
        int i=0,j=0;
        int ans=-1;
        while(i<haystack.size() && j<needle.size()){
              //cout<<i<<" "<<j<<endl;
                while( j > 0 &&haystack[i]!=needle[j]){
                    j = lps[j-1];
                    ans = -1;
                }
              
            if(haystack[i]==needle[j]){
                ans = i-j;
                j++;
            }
            i++;
              //cout<<i<<" "<<j<<endl;
            
        }

        if(j<needle.size()) return -1;
        return ans;
    }
};