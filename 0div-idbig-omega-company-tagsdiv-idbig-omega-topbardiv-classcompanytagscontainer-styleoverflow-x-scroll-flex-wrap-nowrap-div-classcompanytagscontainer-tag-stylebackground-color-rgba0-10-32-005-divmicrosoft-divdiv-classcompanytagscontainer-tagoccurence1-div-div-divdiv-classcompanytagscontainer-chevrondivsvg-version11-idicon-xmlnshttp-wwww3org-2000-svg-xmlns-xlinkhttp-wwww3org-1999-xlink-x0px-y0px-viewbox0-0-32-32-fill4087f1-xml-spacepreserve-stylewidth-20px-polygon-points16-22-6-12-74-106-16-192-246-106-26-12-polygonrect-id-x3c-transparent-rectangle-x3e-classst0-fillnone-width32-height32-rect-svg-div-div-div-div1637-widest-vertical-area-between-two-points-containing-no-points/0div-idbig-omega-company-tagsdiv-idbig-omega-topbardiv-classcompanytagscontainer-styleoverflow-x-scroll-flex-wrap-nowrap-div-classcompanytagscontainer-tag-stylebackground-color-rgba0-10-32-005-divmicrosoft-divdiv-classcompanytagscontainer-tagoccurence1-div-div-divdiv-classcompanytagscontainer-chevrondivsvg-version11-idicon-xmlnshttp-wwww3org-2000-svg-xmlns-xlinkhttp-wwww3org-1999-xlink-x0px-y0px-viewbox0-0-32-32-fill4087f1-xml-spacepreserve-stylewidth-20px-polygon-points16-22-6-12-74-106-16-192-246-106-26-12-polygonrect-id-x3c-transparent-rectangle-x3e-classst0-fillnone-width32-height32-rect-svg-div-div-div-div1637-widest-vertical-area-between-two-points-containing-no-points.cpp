class Solution {
public:
    
    bool static sortcol(const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0];
    }
    
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        
        sort(points.begin(), points.end(), sortcol);
        
        int n = points.size();
        int ans = 0;
        
        for(int i = 1;i < n;i++){
            if(points[i][0] > points[i-1][0] and abs(points[i][0] - points[i-1][0]) > ans){
                ans = abs(points[i][0] - points[i-1][0]);
            }    
        }
        
        
        return ans;
        
    }
};