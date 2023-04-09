class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int>s;
        
        for(auto q:nums) s.insert(q);
        
        return nums.size() != s.size();
    }
};