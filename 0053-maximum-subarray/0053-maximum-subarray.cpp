class Solution {
public:
    int maxSubArray(vector<int>& v) {
        
        int len = v.size();
        int sum = 0;
        int ans = INT_MIN;
        
        for(int i = 0;i < len ;i++){
            sum += v[i];
            ans = max(ans,sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return ans;
    }
};