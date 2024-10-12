class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // left array stores till what index this element is minimum simillarly
        int n = arr.size();
        int mod = 1e9+7;
        vector<int> left;
        stack<int> st;
        st.push(0);
        left.push_back(-1);
        for(int i=1;i<n;i++){
            while(!st.empty() &&  arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){left.push_back(-1);}
            else{left.push_back(st.top());}
            st.push(i);
        }

        while(!st.empty()) st.pop();
        vector<int> right;
        right.push_back(n);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()){right.push_back(n);}
            else right.push_back(st.top());
            st.push(i);
        }
        reverse(right.begin(),right.end());
        //for(int i=0;i<n;i++) cout<<left[i]<<" "<<right[i]<<endl;
        long long int  ans =0;
        for(int i=0;i<n;i++){
           long long lefti = i-left[i];
            long long righti = right[i]-i;
            long long temp=(lefti*righti);
            ans = (ans+(arr[i]*temp))%mod;
        }
        return ans%mod;
    }
};