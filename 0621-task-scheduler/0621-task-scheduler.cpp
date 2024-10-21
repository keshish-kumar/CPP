class Solution {
public:

    // O(n)
    // priority_queu log(priority_queue size()) , log(26)
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        for(int i=0;i<tasks.size();i++) mp[tasks[i]]++;
        priority_queue<int> pq;
        for(auto it:mp) pq.push(it.second);
        int ans=0;
        while(!pq.empty()){
            // we have to push it till n times.
           queue<int> q;
           // we have to run this loop for n+1 times if n=2 than A,B,idle after A we need two more cycle 
           for(int i=1;i<=n+1;i++){
              if(!pq.empty()){
                q.push(pq.top());
                pq.pop();
              }
           }

            int temp = q.size();
            // than we have to push element in q if >=1 , 
            while(!q.empty()){
                int t = q.front()-1;
                q.pop();
                if(t>0)
                    pq.push(t);
            }

            if(!pq.empty()) // if pq is not empty than it will take n+1 cycle
                ans += n+1;
            else ans += temp; // if empty than it ends and we have to return only last eleemnt not the idle time.

        }
        return ans;
    }
};