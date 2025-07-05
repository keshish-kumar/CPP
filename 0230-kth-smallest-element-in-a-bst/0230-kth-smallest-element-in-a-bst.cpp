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
    int kthSmallest(TreeNode* root, int k) {
        
        priority_queue<int> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* t = q.front();
                pq.push(t->val);
                q.pop();
                if(t->left!=NULL) q.push(t->left);
                if(pq.size()>k)pq.pop();
                if(t->right!=NULL) q.push(t->right);
                if(pq.size()>k)pq.pop();
            }
            
        }
        return pq.top();
    }
};