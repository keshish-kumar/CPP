class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==2){
                     q.push({i,j});
                     
                }
            }
        }
        vector<int> ii = {-1, 0, 1, 0};
        vector<int> jj = {0, 1, 0, -1};
        while(!q.empty()){
            int n = q.size();
            bool flag = false;
            while(n--){
                int ni = q.front().first;
                int nj = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int i = ii[k]+ni;
                    int j = jj[k]+nj;
                    if(i>=0 && j>=0 && i<mat.size() && j<mat[0].size() && mat[i][j]==1){
                        q.push({i,j});
                        mat[i][j] = 2;
                        flag = true;
                    }
                }
            }
            if(flag==true) ans++;
        }
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) return -1;
            }
        }
        return ans;
    }
};