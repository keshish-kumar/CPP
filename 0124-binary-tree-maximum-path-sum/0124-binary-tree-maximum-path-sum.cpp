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
        if(root==NULL) return -1e9;
        if(root->left == NULL && root->right == NULL){
            ans = max(ans,root->val);
            return root->val;
        }

        int left = solve(root->left,ans);
        int right = solve(root->right,ans);

        ans = max({ans,root->val,left+right+root->val,left+root->val,right+root->val});
        return max({left+root->val,right+root->val,root->val});
    }
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};