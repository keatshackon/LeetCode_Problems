class Solution {
public:
    int solve(int idx,vector<int>&nums,vector<int>&dp){
        
        if(idx == nums.size()-1){
            dp[idx] = nums[idx];
            return nums[idx];
        }else if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int s1 = nums[idx] + solve(idx+2,nums,dp);
        int s2 = solve(idx+1,nums,dp);
        
        return dp[idx] = max(s1,s2);
    }
    
    int rob(vector<int>& nums) {
        
//         int sum = 0;
//         int idx = 0;
//         vector<int>dp(nums.size(),-1);
        
//         solve(idx,nums,dp);

    
//         return dp[0];
        
        
        int s1 = nums[0];
	    int s2 = 0;

	    for (int i = 1; i < nums.size(); i++) {

		    int k1 = nums[i];
		    if (i > 1) {
			    k1 += s2;
		    }
		    int k2 = s1;
		    s2 = s1;
		    s1 = max(k1, k2);
	    }
	    return  s1;
    }
};