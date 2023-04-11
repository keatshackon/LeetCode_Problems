class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 1) return 0;
        
        int min_so_far = prices[0];
        int n = prices.size();
        int ans = 0;
        
        for(int i = 1;i < n;i++){
            if(prices[i] > min_so_far){
                ans = max(ans,prices[i] - min_so_far);
            }else{
                min_so_far = prices[i];
            }
        }
        
        return ans;
        
    }
};