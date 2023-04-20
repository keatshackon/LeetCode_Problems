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
    
    void solve(TreeNode *root1,TreeNode* root2){
        if(root1 ==  NULL and root2 == NULL){
            return;
        }
        
        root1->val += root2->val;
        
        if(root1->left != NULL and root2->left != NULL){
            solve(root1->left,root2->left);
        }else if(root1->left == NULL and root2->left != NULL){
            root1->left = root2->left;
            root2->left = NULL;
            // return;
        }
        // else if(root1->left != NULL and root2->left == NULL){
        //     return;
        // }
        
        if(root1->right != NULL and root2->right != NULL){
            solve(root1->right,root2->right);
        }else if(root1->right == NULL and root2->right != NULL){
            root1->right = root2->right;
            root2->right = NULL;
            return;
        }
        // else if(root1->right != NULL and root2->right == NULL){
        //     return;
        // }
        
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL){
            return root2;
        }else if(root2 == NULL){
            return root1;
        }
        
        solve(root1,root2);
        
        return root1;
        
    }
};