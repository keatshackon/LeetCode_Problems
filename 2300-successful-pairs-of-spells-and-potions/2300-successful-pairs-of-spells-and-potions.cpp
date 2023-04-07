class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());
        
        vector<int>ans;
        
        int n = spells.size();
        int m = potions.size();
        
        for(int i = 0;i < n;i++){
            
            long long res = spells[i];
            
            int l = 0;
            int r = m - 1;
            int s1 = -1;
            
            while(l <= r){
                int mid = (l+r)/2;
                
                if(potions[mid] * res >= success){
                    s1 = mid;
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            if(s1 != - 1)
                ans.push_back(m-s1);
            else
                ans.push_back(0);
            
        }
        
        return ans;
    }
};