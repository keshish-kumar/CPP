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
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            int n = q.size();
            while(n--){
                TreeNode* node = q.front(); q.pop();
                if(st.find(k-node->val)!=st.end()) return true;
                st.insert(node->val);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            
        }
         return false;
    }
};