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
    
    int maximum(TreeNode* root, int & ans){
        
        if(root==NULL) return 0;
        
        int lh = maximum(root->left,ans);
        int rh = maximum(root->right,ans);
        if(lh<0) lh=0;
        if(rh<0) rh =0;
        ans = max(ans,lh+rh+root->val);
        return root->val + max(lh,rh);
    }
    
    int maxPathSum(TreeNode* root) {
        // same as height of binary tree just we have to add node here
        int ans = -1e9;
        
        maximum(root,ans);
        return ans;
    }
};