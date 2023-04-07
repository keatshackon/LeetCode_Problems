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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL)  return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool leftToRight = true;
        while(!q.empty()){
            int len  = q.size();
            vector<int>temp(len);
            int k = 0;
            while(k < len){
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                } 
                
                if(leftToRight){
                    temp[k] = q.front()->val;
                }else{
                    temp[len-k-1] = q.front()->val;
                }
                k++;
                q.pop();
            }
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};