class Solution {
public:
    bool solve(map<int,int>& st, int k,int last,int lastjump,vector<vector<int>>& dp){
        if(k>last){
            return false;
        }
        if(k==last) return true;
        if(dp[st[k]][st[lastjump]]!=-1) return dp[st[k]][st[lastjump]];
        bool flag =false;
        // first check if it is possible to jump k-1
        if( st.find(k+lastjump-1)!=st.end() && (k)!=(k+lastjump-1)){
            flag = flag || solve(st,lastjump+k-1,last,lastjump-1,dp);
        }
        // jump k
        if(  st.find(lastjump+k)!=st.end() ){
            flag = flag || solve(st,lastjump+k,last,lastjump,dp);
        }

        // jump k+1
        if(st.find(lastjump+k+1)!=st.end() ){
            flag = flag || solve(st,lastjump+k+1,last,lastjump+1,dp);
        }

        return dp[st[k]][st[lastjump]] = flag;

    }
    bool canCross(vector<int>& stones) {
         map<int,int> st;
         // set is used to check wether jumped node is stone or not 
         // stones are only stored in set
         if(stones[1]!=1) return false;
         for(int i=1;i<stones.size();i++)
            st[stones[i]]=i;
        int last = stones[stones.size()-1];
        int lastjump = 1;
        vector<vector<int>> dp(stones.size()+1,vector<int>(stones.size()+1,-1));
        return solve(st,1,last,lastjump,dp);
    }
};