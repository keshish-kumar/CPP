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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* node = q.front().first;
                int level =q.front().second;
                q.pop();
                mp[level] = node->val;
                if(node->left!=NULL) q.push({node->left,level+1});
                if(node->right != NULL) q.push({node->right,level+1});
            }
        }
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
};