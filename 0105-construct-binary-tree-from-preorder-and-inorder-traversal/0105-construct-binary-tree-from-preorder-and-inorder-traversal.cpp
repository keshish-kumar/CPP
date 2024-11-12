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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index){
        if(start>end) return NULL;
        //if(index==preorder.size()) return NULL;

        int j=0;
        for( j=start;j<=end;j++) if(inorder[j]==preorder[index]) break;
        TreeNode* node = new TreeNode(preorder[index]);
        index++;
        node->left =  solve(preorder,inorder, start, j-1, index);
        node->right = solve(preorder,inorder, j+1,   end, index);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index =0;
        return solve(preorder,inorder,0,preorder.size()-1,index);
    }
};