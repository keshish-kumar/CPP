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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start, int end, int & index){
        if(start>end) return NULL;
        int value = preorder[index];
        int i;
        for( i=start;i<=end;i++) if(value == inorder[i]) break;

        // first left
        index++;
        TreeNode* node = new TreeNode(value);
        node->left = solve(preorder,inorder,start,i-1,index);
        node->right = solve(preorder,inorder,i+1,end,index);

        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return solve(preorder,inorder,0,inorder.size()-1,index);
    }
};