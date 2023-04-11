class Solution {
public:
    string removeStars(string s) {
        
        stack<char>st;
        int n = s.length();
        string ans = "";
        int i = n - 1;
        
        while(i >= 0){
            
            if(s[i] == '*'){
                st.push('*');
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    ans += s[i];
                }
            }
            i--;
        }
        
        reverse(begin(ans),end(ans));
        
        return ans;
    }
};