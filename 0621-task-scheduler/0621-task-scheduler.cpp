class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> p1,p2;
        vector<int> v(26,0);
        for(char it:tasks)
            v[it-'A']++;
        for(int it:v)
            if(it>0) p1.push(it);
        // Now that we have all the counts in p1;
        int ans =0;
        while(!p1.empty()){
            int t = n+1;
            while(t>0 && !p1.empty()){
                int no = p1.top();p1.pop();
                no = no-1;
                if(no>0) p2.push(no);
                ans++;
                t--;
            }
            
            while(!p2.empty()){
                int no = p2.top();p2.pop();
                p1.push(no);
            }
            if(!p1.empty() ) ans += t; // only add idle time if task are still left this will protect if lastb have only 2 lement but n is 6 so extra 4 will be claculated .
            
        }
        return ans;
    }
};