class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();
        
        if(n > m){
            return false;
        }
        
        vector<int>arr(26,0);
        
        for(int i = 0;i < n;i++){
            arr[s1[i] - 'a']++;
        }
        
        vector<int>temp(begin(arr),end(arr));
        
        int i = 0;
        int k = m - n;

        while(i <= k){
            if(arr[s2[i] - 'a'] > 0){
                int j = i;
                int cnt = 0;
                temp = arr;
                while(j < m and j < i + n and temp[s2[j] - 'a'] > 0){
                    temp[s2[j] - 'a']--;
                    cnt++;   
                    j++;
                    if(cnt == n){
                        return true;
                    }
                }
            }
            i++;
        }
        return false;
    }
};