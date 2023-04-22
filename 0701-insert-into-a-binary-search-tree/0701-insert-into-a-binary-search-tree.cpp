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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL){
            return new TreeNode(val);
        }
        
        TreeNode *cur = root,*prev = NULL;
        
        TreeNode *nNode = new TreeNode(val);
        
        while(cur != NULL){
            if(cur->val > val){
                prev = cur;
                cur = cur->left;
            }else{
                prev = cur;
                cur = cur->right;
            }
        }
        
        if(val > prev->val){
            prev->right = nNode;
        }else{
            prev->left = nNode;
        }
        
        return root;
        
    }
};