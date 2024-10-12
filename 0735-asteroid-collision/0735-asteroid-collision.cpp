class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int> st;
        for(int i=0;i<n-1;i++) st.push(asteroids[i]);

        // Now we will pop this one by ones and check that
        stack<int> st2;
        st2.push(asteroids[n-1]);

        while(!st.empty() ){
            
            while( !st2.empty() &&  !st.empty() && st.top()> 0 && st2.top()<0){
                if(abs(st2.top())<st.top()){
                    st2.pop();
                }
                else if(abs(st2.top())==st.top()){
                    st.pop();st2.pop();
                }
                else{
                    st.pop();
                }
            }
            
            if(!st.empty()){
                st2.push(st.top());
                st.pop();
            }
            
        }

        vector<int> ans;
        while(!st2.empty()){
         
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
};