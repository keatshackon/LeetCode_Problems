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
    
    bool solve(TreeNode *root,int sum,int target){
        
        //cout<<sum<<"\n";
        
        if(root == NULL){
            return false;
        }
        
        else if(sum + root->val == target and root->left == NULL and root->right == NULL){
            return true;
        }
                
        bool s1 = solve(root->left,sum+root->val,target);
        if(s1) return true;
        
        bool s2 = solve(root->right,sum+root->val,target);

            
        return s1 or s2;
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL){
            return false;
        }
        
        int sum = root->val;
        
        if(sum == targetSum and root->left == NULL and root->right == NULL){
            return true;
        }
        
        return solve(root->left,sum,targetSum) or solve(root->right,sum,targetSum);
    }
};