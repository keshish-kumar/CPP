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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>>  q;
        map<int,map<int,vector<int>>> mp; // first is vertical length than horizontal length
        q.push({root,{0,0}});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* node = q.front().first;
                int length = q.front().second.first;
                int level = q.front().second.second;
                q.pop();
                mp[length][level].push_back(node->val);
                if(node->left!=NULL)  q.push({node->left,{length-1,level+1}});
                if(node->right!=NULL) q.push({node->right,{length+1,level+1}});
            }
        }
        for(auto it:mp){
            vector<int> temp;
            for(auto i:it.second){
                sort(i.second.begin(),i.second.end()); // each level should be sorted
                temp.insert(temp.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};