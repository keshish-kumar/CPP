class Solution {
public:
    void solve(int n, string& ans){
        if(n==1) return;
        char ch = '1';
        string temp = "";
        int count = 1;
        for(int i=ans.size()-2;i>=0;i--){
            if(ch == ans[i]){
                count++;
            }
            else{
                temp = to_string(count) + ch + temp;
                count=1;
                ch = ans[i];

            }
        }
        temp = to_string(count) + ch + temp;
        cout<<temp<<endl;
        ans = temp;
        solve(n-1,ans);
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        string  ans = "1";
        solve(n,ans);
        return ans;

    }
};