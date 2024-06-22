//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 
  
  void count(string s1, unordered_map<char,int>& m1, int i , int & ans){
      if(i>=s1.size()){
          return ;
      }
      
      if(m1.find(s1[i])==m1.end()){
          m1[s1[i]] = ans;
          ans = ans*2;
          
      }
      else{
          int temp = m1[s1[i]];
          m1[s1[i]] = ans;
          ans = ans*2;
          ans = ans-temp;
      }
      count(s1,m1,i+1,ans);
  }
  
  
  
    string betterString(string str1, string str2) {
        // code here
        // unordered_set<string> st1,st2;
        // string temp1="",temp2="";
        
        // count(st1,st2,str1,str2,temp1,temp2,0);
        
        // if(st1.size()==st2.size()){
        //     return str1;
        // }
        // else if(st1.size()>st2.size())
        //     return str1;
        // else
        //     return str2;
        
        // next appro
        
            
    
        
        // next approach is using power set concept
        // for duplicates chaarcter we have to store the previous set size and subtract it from new set
        // for storing both chacter and size of subsequnece before it we wiil store both c ahacter and its previous subsequences
        
        unordered_map<char,int> m1,m2;
        int ans1 = 1,ans2 = 1;
        count(str1,m1,0,ans1);
        count(str2,m2,0,ans2);
        
        if(ans1>=ans2) return str1;
        else return str2;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends