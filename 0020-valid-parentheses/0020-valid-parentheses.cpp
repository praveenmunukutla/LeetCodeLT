class Solution {
	unordered_map<char, char> map;
    stack<char> sta;
public:    
    bool isValid(string s) {
        map[')']='(';
        map['}']='{';
        map[']']='[';
        for(int i = 0; s[i] != '\0'; i++){
            if(map.find(s[i]) == map.end()){
                sta.push(s[i]);
            }else{
                if(sta.empty() || sta.top() != map[s[i]])
                    return false;
                sta.pop();
            }
        }
        
        return sta.empty() == true;
    }
};