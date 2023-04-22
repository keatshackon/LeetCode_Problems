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
    // with  Extra Space 
//     void solve(TreeNode*root, vector<int> &v) {

// 	    if (root == NULL) {
// 		    return;
// 	    }
// 	    solve(root->left, v);
// 	    v.push_back(root->val);
// 	    solve(root->right, v);
//     }

    
    // Second Appraoche Range wala
    bool solve1(TreeNode *root,long a,long d){
        
        if(root == NULL){
            return true;
        }
        if(root->val >= a and root->val <= d){
            return solve1(root->left,a,root->val-1l) and solve1(root->right,root->val+1l, d);    
        }else{
            return false;
        } 
        
    }
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }
        
        long a = INT_MIN;
        long b = INT_MAX;
        
        return solve1(root,a,b);
        
        
       
    }
};