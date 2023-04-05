class Solution {
public:
    int partitionString(string s) {

        map<char, int>m;
        int len = s.length();
        int cnt = 0;

        for (int i = 0; i < len; i++) {
            if (m.count(s[i]) == 0) {
                m[s[i]] = 1;
            } else {
                cnt++;
                m.clear();
                m[s[i]] = 1;
            }
        }
        cnt++;

        return cnt;
    }
};