class Solution {
public:
    static inline void reverseString(string& s, int start, int end){
        while (start <= end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string str){
        while (str[0] == ' ')
            str.erase(str.begin());
        while (str[str.length() - 1] == ' ')
            str.erase(str.end() - 1);
        int sIndex = -1;
        for(int i = 0; str[i] != '\0'; i++){
            if(sIndex == -1 && i > 0 && str[i]==' ' && str[i-1]==' '){
                sIndex = i;
            }else if(sIndex != -1  && str[i] != ' '){
                str[sIndex++] = str[i];
            }else if(sIndex != -1 && i > 0 && str[i] == ' ' && str[i-1] != ' '){
                str[sIndex++] = ' ';
            }
        }
        
        if(sIndex != -1)
            str.erase(str.begin()+sIndex, str.end());
        reverseString(str, 0, str.length() - 1);
        int i, start;
        for (i = 0, start = 0; str[i] != '\0'; i++){
            if (str[i] == ' '){
                reverseString(str, start, i - 1);
            }
            else if (str[i] != ' '&& i > 0 && str[i - 1] == ' '){
                start = i;
            }
        }
        reverseString(str, start, str.length() - 1);
        return str;
    }
};