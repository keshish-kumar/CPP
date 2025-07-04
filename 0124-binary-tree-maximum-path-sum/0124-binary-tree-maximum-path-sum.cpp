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
    int solve(TreeNode* root, int & ans){
        if(root==NULL) return 0;
        int l = solve(root->left,ans);
        int r = solve(root->right,ans);
        if(l<0) l=0;
        if(r<0) r=0;
        ans = max(ans,l+r+root->val);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans =INT_MIN;
        solve(root,ans);
        return ans;
    }
};