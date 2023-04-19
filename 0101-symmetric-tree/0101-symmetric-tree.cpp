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
    
    bool solve(TreeNode *l1,TreeNode *l2){
        if(l1 == NULL and l2 == NULL){
            return true;
        }else if((l1 == NULL and l2 != NULL) ){
            return false;
        }else if((l1 != NULL and l2 == NULL)){
            return false;
        }
        
        if(l1->val != l2->val){
            return false;
        }
        
        int s1 = solve(l1->left,l2->right);
        int s2 = solve(l1->right,l2->left);
        
        return s1 and  s2;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }
        
        return solve(root,root);
        
    }
};