class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        map<char,int> mp;
        for(int i=0;i<tasks.size();i++) mp[tasks[i]]++;
        for(auto it:mp) pq.push(it.second);

        int ans =0;
        while(!pq.empty()){
            int k = 0;
            vector<int> temp;
            while(!pq.empty()){
                //int f =  pq.top();
                if(pq.top()-1>0)
                   {temp.push_back(pq.top()-1);}
                pq.pop();
               
                k++;
                if(k==(n+1)) break;
            }
            
            for (int count : temp) {
                pq.push(count);
            }

            // If the queue is empty, add only k (tasks processed), otherwise, add n+1 (full cycle)
            ans += pq.empty() ? k : (n + 1);
        }
        return ans;
    }
};