class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       
       vector<int> v(26,0);
        for(int i=0;i<tasks.size();i++){
            v[tasks[i]-'A']++;
        }
        sort(v.begin(),v.end());
        int t = v[25];
        int gap = t-1;
        int idleslot  = (t-1)*n;

        for(int i=24;i>=0;i--){
            idleslot -= min(gap,v[i]);
        }

        if(idleslot>0) return tasks.size()+idleslot;
        return  tasks.size();
       
    }
};