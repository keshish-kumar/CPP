class Solution {
public:
    bool check(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        
        int maxi = 0;
        int row=0,col=0;
        //cout<<"  0"<<" ";
        //for(int i=0;i<n;i++) cout<<s2[i]<<" ";
        //cout<<endl;
        //cout<<"0"<<" ";
        for(int i=0;i<=n;i++){
           // if(i!=0) cout<<s[i-1]<<" ";
            for(int j=0;j<=n;j++){
                if(i==0||j==0) dp[i][j] = 0;
                else{
                    if(s[i-1] == s2[j-1]){
                        dp[i][j] = dp[i-1][j-1]+1;
                        if(maxi < dp[i][j]){
                            row = i;
                            col=j;
                            maxi = dp[i][j];
                        }
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
               // cout<<dp[i][j]<<" ";
            }

           // cout<<endl;
            
        }
        string  ans = "";
        for(int i=1;i<=n ;i++){
            for(int j=1;j<=n;j++){
                string temp ="";
                int row=i,col=j;
                if(dp[row][col]>ans.size()){
                    while(dp[row][col]>0){
                    temp += s[row-1];
                    row--;col--;
                    }
                    if(check(temp)) ans = temp;
                }
            }
        }
      
        return ans;
    }
};