class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int min_so_far = prices[0];
        int n = prices.size();
        int profit = 0;
        
        for(int i = 1;i < n;i++){
            if(min_so_far < prices[i]){
                profit = max(profit,prices[i] - min_so_far);
            }else{
                min_so_far = min(min_so_far,prices[i]);
            }
        }
        return profit;
    }
};