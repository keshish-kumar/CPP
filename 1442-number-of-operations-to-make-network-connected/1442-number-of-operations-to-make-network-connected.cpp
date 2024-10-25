class Solution {
public:
    // find operation with compression to handle skewness
    int find(int x, vector<int>& parent){
        if(parent[x]==x) return x;

        return parent[x] = find(parent[x],parent);
    }

    // union by rank operation , to avoid skewnees
    void unionr(int x1, int x2, vector<int>& parent, vector<int>& rank){
        int x1_parent = find(x1,parent);
        int x2_parent = find(x2,parent);
        if(x1_parent==x2_parent) return;
        // whose rank is greate make them parent
        if(rank[x1_parent]>rank[x2_parent]){
            parent[x2_parent]=x1_parent; 
        }
        else if(rank[x1_parent]<rank[x2_parent]){
            parent[x1_parent]=x2_parent;
        }
        else{ // if ranks are equal than make anyone parent and increase parent rank.
            parent[x1_parent]=x2_parent;
            rank[x2_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
         if (connections.size() < n - 1) return -1; 
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n,0);
        int components=n;
        for(int i=0;i<connections.size();i++){
            int x = find(connections[i][0],parent);
            int y = find(connections[i][1],parent);
            
            if(x!=y){
                unionr(connections[i][0],connections[i][1],parent,rank);
                components--;
            }
        }
        return components-1;
    }
};