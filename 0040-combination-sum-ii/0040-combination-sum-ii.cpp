class Solution {
public:
    
    void solve(int n,vector<int>&c_grp,int target,vector<int>&ds,vector<vector<int>>&ans){
        
        if(target == 0){
            ans.push_back(ds);
            return;
        }else if(target < 0 or n == c_grp.size()){
            return;
        }
        
        for(int i = n;i < c_grp.size();i++){
            if(i > n and c_grp[i] == c_grp[i-1]) continue;
            
        
            ds.push_back(c_grp[i]);
            solve(i+1,c_grp,target-c_grp[i],ds,ans);
            ds.pop_back();
        }   
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        
//         vector<pair<int,int>>c_grp;
//         map<int,int>m;
//         int n = 0;
        
//         for(auto q:candidates){
//             ++m[q];
//         }
        
//         for(auto q:m){
//             c_grp.push_back({q.first,q.second});
//         }
        
        solve(0,candidates,target,ds,ans);
        
        return ans;
        
    }
};