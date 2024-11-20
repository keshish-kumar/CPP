//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans =0;
        while(!pq.empty()){
            int i=pq.top().second.first;
            int j = pq.top().second.second;
            int dist = pq.top().first;
            pq.pop();
            
            if(visited[i][j]==1) continue;
            visited[i][j] = 1;
            if(i==grid.size()-1 && j==grid[0].size()-1) ans = dist;
            vector<int> ii = {0,1,0,-1};
            vector<int> jj = {1,0,-1,0};
            for(int k=0;k<4;k++){
                int r = i+ii[k];
                int c = j+jj[k];
                
                if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && visited[r][c]==0){
                    pq.push({dist+grid[r][c],{r,c}});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends