class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // we will udse bfs approach here
        int ans = 0;
        queue<pair<int, int>> q;

        vector<int> ii = {0, 1, 0, -1};
        vector<int> jj = {1, 0, -1, 0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) {q.push({i, j});}
            }
        }
        
        while (!q.empty()) {
            bool answer = false;
            int n = q.size();
            while (n--) {
                for (int k = 0; k < 4; k++) {
                    int r = q.front().first + ii[k];
                    int c = q.front().second + jj[k];
                    if (r >= 0 && c >= 0 && r<grid.size() && c<grid[0].size() && grid[r][c] == 1) {
                        answer = true;
                        grid[r][c] = 2;
                        q.push({r, c});
                    }
                }
                q.pop();
            }
            if (answer == true)
                ans++;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};