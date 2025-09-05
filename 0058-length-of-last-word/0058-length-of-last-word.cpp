class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int count = 0;
        int i;
        for(i = len-1; i >= 0; i--){
            if(s[i] == ' ' && count == 0) continue;
            else if(s[i] == ' ') break;
            count++;
        }
        return count;
    }
};