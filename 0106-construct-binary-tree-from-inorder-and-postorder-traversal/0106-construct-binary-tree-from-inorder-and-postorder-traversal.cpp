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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start,int end, int& index){
        if(start>end) return NULL;
     
        int value = postorder[index];
        int i;
        for(  i = start;i<=end;i++)
            if(value == inorder[i]) break;
        
        // at index j it found the root;
        TreeNode* node = new TreeNode(value);
        index--;
       
        node->right = solve(inorder,postorder,i+1,end,index);
        node->left = solve(inorder,postorder,start,i-1,index);
         
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        return solve(inorder,postorder,0,inorder.size()-1,index);
    }
};