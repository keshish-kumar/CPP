class Solution {
public:


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left;
        vector<int> right;
        stack<int>  q,q2;
        q.push(0);
        left.push_back(-1);
        for(int i=1;i<n;i++){
            while(!q.empty() && heights[q.top()]>heights[i] ){
                    q.pop();
            }
            if(q.empty()) left.push_back(-1);
            else{
                left.push_back(q.top());
            }
            q.push(i);
        }

        right.push_back(n);
        q2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!q2.empty() && heights[q2.top()]>=heights[i]){
                q2.pop();
            }
            if(q2.empty()) right.push_back(n);
            else{
                right.push_back(q2.top());
            }
            q2.push(i);
        }

        int ans = INT_MIN;
        reverse(right.begin(),right.end());
        for(int i=0;i<n;i++){
            cout<<left[i]<<" "<<right[i]<<endl;
            ans = max(ans,((right[i]-left[i]-1)*heights[i]));
        }
    return ans;
    }
};