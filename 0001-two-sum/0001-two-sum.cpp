class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        unordered_map<int,int>m;
        
        for(int i = 0;i < n;i++){
            if(m.count(target - nums[i]) == 0){
                m[nums[i]] = i;
            }else{
                return {m[target-nums[i]],i};
            }
        }
        
        return {};   
    }
};