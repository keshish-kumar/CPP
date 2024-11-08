class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0) st.push(asteroids[i]);
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                    st.pop();
                }

                if(st.empty() || st.top()<0) st.push(asteroids[i]);
                else if(st.top()==abs(asteroids[i]) && asteroids[i]<0 && st.top()>0) st.pop();
            }
        }

        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(),v.end());
        return v;

    }
};