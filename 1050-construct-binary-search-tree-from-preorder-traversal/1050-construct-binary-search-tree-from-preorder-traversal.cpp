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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index, int start, int end){
        if(start>end || start<0 || end<0 ) return nullptr;
        // first we need to search were unorder first element is present in the preorder vectior
        int i=start;
        while(i<=end){
            if(inorder[i] == preorder[index]) break;
            i++;
        }
        TreeNode*  root = new TreeNode(preorder[index]);
        index++;
        root->left = solve(preorder,inorder,index,start,i-1);
        root->right = solve(preorder,inorder,index,i+1,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int index=0;
        return solve(preorder,inorder,index,0,preorder.size()-1);
    }
};