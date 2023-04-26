class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>&nums,vector<vector<int>>&dp){
        
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int s1 = nums[i][j] + solve(i+1,j,nums,dp);
        int s2 = nums[i][j] + solve(i+1,j+1,nums,dp);
        
        dp[i][j] = min(s1,s2);
        
        return dp[i][j];
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        
        int row = triangle.size();
        int col = row;
        vector<vector<int>>dp(row,vector<int>(col,-1));
        //solve(0,0,triangle,dp);
        
        dp[0][0] = triangle[0][0];
        for(int i = 1;i < row;i++){
            for(int j = 0;j < triangle[i].size();j++){
                int up = INT_MAX;
                int antidia = INT_MAX;
                if(j > 0){
                    antidia = dp[i-1][j-1];
                }
                if(j < triangle[i].size()-1){
                    up = dp[i-1][j];
                }            
                dp[i][j] = triangle[i][j] + min(up,antidia);
            }
        }
        
        // for(auto q:dp){
        //     for(auto w:q){
        //         cout<<w<<" ";
        //     }
        //     cout<<"\n";
        // }
    
        int ans = INT_MAX;
        for(int i = 0;i <row;i++){
            ans = min(ans,dp[row-1][i]);
        }
        
        return ans;
    }
};







