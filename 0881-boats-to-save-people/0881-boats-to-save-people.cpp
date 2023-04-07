class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());
        
        int cnt = 0;
        int n = people.size();
        
        int i = 0;
        int j = n - 1;
        
        while(i <= j){
            
            if(i != j and people[i] + people[j] <= limit){
                cnt++;
                i++;
                j--;
            }else if(i != j and people[i] + people[j] > limit){
                j--;
                cnt++;
            }
            
            if(i == j){
                cnt++;
                break;
            }
        } 
       
        
        return cnt;
    }
};