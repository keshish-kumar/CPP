class Solution {
public:
    static bool func(string & w1,string& w2){
        return w1.size()<w2.size();
    }
    bool predecesor(string s1,string s2){
        int n = s1.size(); // index i
        int m = s2.size(); // prev j
        if(n!=(m+1)) return false;
        int i=0,j=0;
        while(j<s2.size() && i<s1.size()){
            if(s1[i]==s2[j])
                j++;
            i++;
        }
        return j==s2.size();
    }
    int solve(vector<string>& words, int index,int prev,vector<vector<int>>& dp){
        if(index==words.size()){
            return 0;
        }

        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int take=0;
        // take
        if(prev==-1 ||  predecesor(words[index],words[prev])){
            take= 1+solve(words,index+1,index,dp);
        }
        int nottake = solve(words,index+1,prev,dp);

        return dp[index][prev+1] = max(take,nottake);
    }
    int longestStrChain(vector<string>& words) {
       sort(words.begin(),words.end(),func);
       int n = words.size();
    //    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //    return solve(words,0,-1,dp);

       vector<int> temp(n,1);
        vector<int> index(n);
        index[0] = -1;
        for(int i=1;i<n;i++){
            int maxi = 1;
            index[i] = i;
            for(int j=0;j<i;j++){
                if(predecesor(words[i],words[j])){
                    if(maxi<(temp[i]+temp[j])){
                        maxi = temp[i]+temp[j];
                        index[i] = j;
                    }
                }
            }
            temp[i] = maxi;
        }
        return *max_element(temp.begin(),temp.end());
    }
};