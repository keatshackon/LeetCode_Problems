class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>ans;
        
        map<int,int>m;
        
        int len2 = nums2.size();
        int n = nums1.size();
        
        for(int i = 0;i < n;i++){
            m[nums1[i]]++;
        }
        
        
        for(int i = 0;i < len2;i++){
            if(m.count(nums2[i]) != 0 and m[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        
        return ans;
        
    }
};