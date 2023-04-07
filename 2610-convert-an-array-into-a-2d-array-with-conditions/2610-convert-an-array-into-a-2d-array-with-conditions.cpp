class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        map<int,int>m;
        int n = nums.size();
        vector<vector<int>>ans;
        
        for(int i = 0;i < n;i++){
            m[nums[i]]++;
        }
        
    
        while(m.size()){
            
            vector<int>temp;
            
            for(auto q:m){
                temp.push_back(q.first);
            }
            
            for(int i : temp) {
                if(!--m[i]) m.erase(i);
            }
        
            ans.push_back(temp);
        }
        
        return ans;
    }
};