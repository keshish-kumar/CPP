class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> v(n,vector<int>(n,-1));

        for(int i=0;i<edges.size();i++){
            v[edges[i][0]][edges[i][1]] = edges[i][2];
            v[edges[i][1]][edges[i][0]] = edges[i][2];
          
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==-1) v[i][j]=1e9;
                
            }
            v[i][i]=0;
        }

        for(int via = 0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    v[i][j] = min(v[i][j],v[i][via]+v[via][j]);
                }
            }
        }

        int ans = -1;
        int reachableCities=n;
        for(int i=0;i<n;i++){
            int count=0;
            int d = distanceThreshold;
            for(int j=0;j<n;j++){
                if( i!=j && v[i][j]<=d){count++;}
            }
            if (count < reachableCities || 
               (reachableCities == count && i > ans)) {
             reachableCities = count ;
                ans = i;
            }
        }

        return ans;


    }
};