#include<bits/stdc++.h>
class Solution {
public:
    
    bool is_able_to_eat(vector<int>&piles,int m,int h){
        
        bool ans = true;
        int n = piles.size();
        long long cnt = 0;
        
        for(int i = 0;i < n;i++){
            int temp = piles[i]/m;
            if(piles[i] < m){
                cnt += 1;
            }else if(piles[i] % m == 0){
                cnt += piles[i]/m;    
            }else{
                cnt += temp + 1;
            }
        }
        
        if(cnt > h){
            return false;
        }
        return ans;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int i = 1;
        int j = INT_MIN;
        
        for(auto q:piles){
            
            if(q > j){
                j = q;
            }
        }
        
        int ans = 0;
        
        while(i <= j){
            
            int m = (i+j)/2;
            
            if(is_able_to_eat(piles,m,h)){
                ans = m;
                j = m-1;
            }else{
                i= m+1;
            }
        }
        
        return ans;
    }
};