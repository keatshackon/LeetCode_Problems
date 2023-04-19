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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }
        
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        
        while(!q.empty()){
            
            int n = q.size();
            vector<int>res;
            
            while(n--){
                TreeNode *temp = q.front();
                q.pop();
                res.push_back(temp->val);
                
                if(temp->left != NULL){
                    q.push(temp->left);    
                }
                if(temp->right != NULL){
                    q.push(temp->right);    
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};