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
    
    void solve(TreeNode *root,vector<int>&ans){
        if(root == NULL){
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }
        
        vector<int>ans;
        
        // solve(root,ans);
        
        stack<TreeNode*>st;
        st.push(root);
        
        TreeNode *cur = root->left;
        
        while(!st.empty() or cur != NULL){
            
            while(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            TreeNode *temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            cur = temp->right;
        }
        
        return  ans;
        
    }
};