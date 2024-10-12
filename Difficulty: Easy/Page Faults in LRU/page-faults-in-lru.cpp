//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        deque<int> dq;
        vector<int> v(1001,0);
        int ans = 0;
        // first put in deque C elements
        int j=0;
        while(j<N && dq.size()<C){
            if(v[pages[j]]==0){
                dq.push_back(pages[j]);
                v[pages[j]]=1;
                ans++;
            }
            else{
                stack<int> st;
                while(dq.front()!=pages[j]){
                    st.push(dq.front());
                    dq.pop_front();
                }
                dq.push_back(pages[j]);
                dq.pop_front();
                while(!st.empty()){
                    dq.push_front(st.top()); st.pop();
                }
            }
            j++;
            
        }
        
        
        for(int i=j;i<N;i++){
            if(v[pages[i]]==0){ // if page is not present
                v[pages[i]]=1; // mark it as 1
                v[dq.front()]=0; // mark the least recently used as 0
                dq.pop_front(); // pop the least recently used from front of queue
                dq.push_back(pages[i]); // push the new eleemnt
                ans++; // increment 
            }
            else{ // page is present than we need to append it back of queue
                stack<int> st;
                while(dq.front()!=pages[i]){
                    st.push(dq.front());
                    dq.pop_front();
                }
                dq.push_back(pages[i]);
                dq.pop_front();
                while(!st.empty()){
                    dq.push_front(st.top()); st.pop();
                }
            }
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends