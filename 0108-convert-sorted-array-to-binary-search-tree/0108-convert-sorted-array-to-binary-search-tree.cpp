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
    TreeNode* solve(vector<int>& nums, int i, int j){
        if(i>j) return NULL;

        int mid = (i+j)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = solve(nums,i,mid-1);
        node->right = solve(nums,mid+1,j);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size()-1;
        return solve(nums,0,n);
    }
};