class Solution {
public:
    
    void solve(int idx,int n,int k,vector<int>&ds,vector<vector<int>>&ans){
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }else if(idx == n+1){
            return;
        }
        
        // Picking case
        ds.push_back(idx);
        solve(idx+1,n,k,ds,ans);
        ds.pop_back();
        
        // Not Picking case
        solve(idx+1,n,k,ds,ans);
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>ds;
        vector<vector<int>>ans;
        solve(1,n,k,ds,ans);
        
        return ans;
    }
};