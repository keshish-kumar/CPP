/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int dist, int level, map<int,map<int,vector<int>>>& mp){
        if(root==NULL) return;
        mp[dist][level].push_back(root->val);
        solve(root->left,dist-1,level+1,mp);
        solve(root->right,dist+1,level+1,mp); 
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // we have to consider both level and distance 
        map<int,map<int,vector<int>>> mp; // one is to store the distacne and other is to store the level and other is to store the lemenet
        solve(root,0,0,mp);
        vector<vector<int>> ans;
        for(auto it: mp){
            vector<int> temp;
            for(auto t:it.second){
                sort(t.second.begin(),t.second.end());
                for(int i=0;i<t.second.size();i++) temp.push_back(t.second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};