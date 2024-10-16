class Solution {
public:
    int find(int n, vector<int>& parent){
        if(n==parent[n]) return n;
        return parent[n] = find(parent[n],parent); // compression
    }

    void unionf(int n1, int n2, vector<int>& parent, vector<int>& rank){
        int x1 = find(n1,parent);
        int x2 = find(n2,parent);
        if(x1 == x2) return;
        if(rank[x1]<rank[x2])
            parent[x1] = x2;
        else if(rank[x1] > rank[x2])
            parent[x2] = x1;
        else
        {
            parent[x2] = x1; // if rank is same than make anyone as parent and increase parent rank
            x1++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        // first we will try doing it using map
        vector<int> parent(26);
        vector<int> rank(26,0);
        for(int i=0;i<equations.size();i++) 
        {parent[equations[i][0]-'a'] =  equations[i][0]-'a';
        parent[equations[i][3]-'a'] = equations[i][3]-'a';}
        // First, process all the "==" equations
for (auto &eq : equations) {
    if (eq[1] == '=') {
        unionf(eq[0] - 'a', eq[3] - 'a', parent, rank);
    }
}

// Then, process the "!=" equations
for (auto &eq : equations) {
    if (eq[1] == '!') {
        if (find(eq[0] - 'a', parent) == find(eq[3] - 'a', parent)) return false;
    }
}
return true;
    }
};