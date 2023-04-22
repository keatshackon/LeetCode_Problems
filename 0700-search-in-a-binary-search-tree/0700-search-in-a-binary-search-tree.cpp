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
    TreeNode* searchBST(TreeNode* root, int val) {
    
        if(root == NULL){
            return NULL;
        }
        
        TreeNode *s1 = NULL,*s2 = NULL;
        
        if(root->val == val){
            return root;
        }else if(root->val > val){
            s1 = searchBST(root->left,val);
        }else{
            s2 = searchBST(root->right,val);
        }
        
        if(s1 != NULL){
            return s1;
        }else{
            return s2;
        }
    
        
    }
};