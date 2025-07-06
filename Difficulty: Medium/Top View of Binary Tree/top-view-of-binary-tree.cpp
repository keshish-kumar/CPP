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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        if(root==NULL) return {};
        map<int,int> mp;// stores length and its value
        queue<pair<Node*, int>> q;
        q.push({root,0});
        vector<int> ans;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* node = q.front().first;
                int length = q.front().second;
                q.pop();
                if(mp.find(length)==mp.end()){
                    mp[length] = node->data;
                }
                if(node->left!=NULL) q.push({node->left,length-1});
                if(node->right!=NULL) q.push({node->right,length+1});
            }
        }
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
};