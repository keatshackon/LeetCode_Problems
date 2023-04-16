class Solution {
private:
    
    void rev(string &s,int i,int j){
        
        while(i < j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    
public:
    string reverseWords(string s) {
        
        int i = 0;
        int j = 0;
        int n = s.length();
        
        string temp = "";
        
        while(j < n){
            if(s[j] != ' '){
                temp += s[j];
            }else{
                rev(s,i,j-1);
                i = j + 1;
            }
            j++;
        }
        rev(s,i,j-1);
        return s;
    }
};