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
    int solve(TreeNode* root,int & ans){
        if(root == NULL) return 0;

        int lh = solve(root->left,ans);
        int rh = solve(root->right,ans);
        ans = max(ans,abs(lh-rh));
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int ans =0;
        solve(root,ans);
        return ans>1 ? false:true;
    }
};