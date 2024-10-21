class Solution {
public:

    // O(n)
    // priority_queu log(priority_queue size()) , log(26)
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> v(26,0);
       for(int i=0;i<tasks.size();i++)
        v[tasks[i]-'A']++;
        sort(v.begin(),v.end()); // sort this

        int maxfreq = v[25];
        int gddhe = maxfreq-1;
        int idleslot = n*gddhe;

        for(int i=24;i>=0;i--){
            idleslot -= min(v[i],gddhe);
        }
        if(idleslot<=0) return tasks.size();
        else return tasks.size()+idleslot;
    }
};