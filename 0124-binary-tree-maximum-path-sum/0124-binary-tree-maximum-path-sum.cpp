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
    int solve(TreeNode* root, int& ans){
        if(root==NULL) return 0;

        int lf = solve(root->left,ans);
        int rf = solve(root->right,ans);
        if(lf<0) lf = 0;
        if(rf<0) rf=0;
        ans = max(ans,lf+rf+root->val);
        return max(lf,rf)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
         solve(root,ans);
        return ans;
    }
};