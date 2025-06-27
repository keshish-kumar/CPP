class Solution {
public:
    void solve(vector<vector<int>>& heights,vector<vector<bool>>& t,int i, int j){
        if(t[i][j]) return;
        t[i][j] = true;
        vector<int> ii = {-1,1,0,0};
        vector<int> jj = {0,0,1,-1};
        for(int k=0;k<4;k++){
            int r = i+ii[k];
            int c = j+jj[k];
            if(r>=0 && c>=0 && r< heights.size() && c<heights[0].size() && heights[i][j]<=heights[r][c]){
                solve(heights,t,r,c);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> pta(row,vector<bool>(col,false));
        // 0th col
        for(int i=0;i<row;i++) solve(heights,pta,i,0);
        // 0th row
        for(int i=0;i<col;i++) solve(heights,pta,0,i);

        vector<vector<bool>> atp(row,vector<bool>(col,false));

        // col-1 th col
        for(int i=row-1;i>=0;i--) solve(heights,atp,i,col-1);

        // row-1th row
        for(int i=col-1;i>=0;i--) solve(heights,atp,row-1,i);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                if(atp[i][j]==true && pta[i][j]==true)
                    ans.push_back({i,j});
        }

        return ans;
    }
};