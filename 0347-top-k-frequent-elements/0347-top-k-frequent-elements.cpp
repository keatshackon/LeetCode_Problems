class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>m;
        
        for(auto q:nums) m[q]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto q:m){
            
            if(pq.size() <= k-1){
                pq.push({q.second,q.first});
            }else{
                if(pq.top().first < q.second){
                    pq.pop();
                    pq.push({q.second,q.first});
                }
            }
        }
        
        vector<int>ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        
        return ans;
    }
};