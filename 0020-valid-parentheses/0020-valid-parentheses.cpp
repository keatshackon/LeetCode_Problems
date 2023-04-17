class Solution {
public:
    bool isValid(string A) {
        
        stack<char>st;
        int n = A.length();
        
        for(int i = 0;i < n;i++){
            
            if(A[i] == '(' or A[i] == '{' or A[i] == '['){
                st.push(A[i]);
            }else{
                if(!st.empty() and A[i] == '}' and st.top() == '{'){
                    st.pop();
                }else if(!st.empty() and A[i] == ']' and st.top() == '['){
                    st.pop();
                }else if(!st.empty() and A[i] == ')' and st.top() == '('){
                    st.pop();
                }else{
                    return 0;
                }
            }
        }
        
        return st.empty();
    }
};