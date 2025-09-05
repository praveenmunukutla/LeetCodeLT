class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        unordered_map<int,string> map;
        int i = 0, row = 0;
        bool down = true;
        while(s[i] != '\0'){
            map[row] += s[i];
            if(down == true){
                if(row == numRows-1){
                    down = false;
                }
            }
            if(down == false){
                if(row == 0){
                    down = true;
                }
            }
            
            down == true ? row++ : row--;
            i++;
        }
        
        string result;
        for(int i = 0; i < numRows; i++){
            result += map[i];
        }
        
        return result;
    }
};