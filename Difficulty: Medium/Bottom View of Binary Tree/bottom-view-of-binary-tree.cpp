/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* node = q.front().first;
                int length = q.front().second;
                q.pop();
                mp[length] = node->data;
                if(node->left != NULL)  q.push({node->left,length-1});
                if(node->right != NULL) q.push({node->right,length+1});
            }
        }
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
};