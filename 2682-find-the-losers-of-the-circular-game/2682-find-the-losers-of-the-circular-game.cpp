class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        
        
        map<int,int>m;
        
        int temp = k;
        
        int i = 1;
        m[1] = 1;
    
        while(true){
            
            i += k;
            i = i % n;
            
            if(i == 0){
                i = n;
            }
            
            if(m.count(i) != 0){
                break;
            }else{
                m[i] = 1;
            }
            k += temp;
            
            if(m.size() >= n){
                break;
            }
        }
        
        vector<int>ans;
        
        for(int i = 1;i <= n;i++){
            if(m.count(i) == 0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};