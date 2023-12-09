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
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }
        //Iterative Approache
        
        stack<TreeNode*>st;
        st.push(root);
        vector<int>ans;
        TreeNode *res = root->left;
        
        while(!st.empty() or res != NULL){
            
            
            while(res != NULL){
                st.push(res);
                res = res->left;
            }
            
            TreeNode *cur = st.top(); 
            ans.push_back(cur->val);
            st.pop();
            res = cur->right;
            
            
        }
        return ans;
        
    }
    
};