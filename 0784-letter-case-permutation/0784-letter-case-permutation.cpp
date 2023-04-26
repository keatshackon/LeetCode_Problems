class Solution {
public:
    
    void solve(int idx,int n,string &s,string &ds,vector<string>&ans){
        if(idx == n){
            ans.push_back(ds);
            return;
        }
        
        if(s[idx] >= 'a' and s[idx] <= 'z'){
            ds.push_back(s[idx]);
            solve(idx+1,n,s,ds,ans);
            ds.pop_back();
            
            ds.push_back(s[idx] - 32);
            solve(idx+1,n,s,ds,ans);
            ds.pop_back();
            
        }else if(s[idx] >= 'A' and s[idx] <= 'Z'){
            ds.push_back(s[idx]);
            solve(idx+1,n,s,ds,ans);
            ds.pop_back();
            
            ds.push_back(s[idx] + 32);
            solve(idx+1,n,s,ds,ans);
            ds.pop_back();
            
        }else{
            ds.push_back(s[idx]);
            solve(idx+1,n,s,ds,ans);
            ds.pop_back();
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        
        string ds = "";
        vector<string>ans;
        
        int n = s.length();
        
        solve(0,n,s,ds,ans);
        
        return ans;
    }
};