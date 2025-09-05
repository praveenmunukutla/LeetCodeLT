class Solution {
    vector<vector<int>> cache;
public:
    bool findMatch(string& str, string& pat, int spos, int ppos){
        if(spos == -1 && ppos == -1)
            return true;
        
        if(spos < -1 || ppos == -1)
            return false;
        
        if(cache[spos+1][ppos+1] != -1)
            return cache[spos+1][ppos+1] == 1 ? true : false;

        if(pat[ppos] == '?')
            return cache[spos+1][ppos+1] = findMatch(str, pat, spos-1, ppos-1);
        else if(pat[ppos] == '*'){
            if(findMatch(str, pat, spos, ppos-1))
                return cache[spos+1][ppos+1] = true;
            
            if(spos >= 0 && ppos == 0)
                return cache[spos+1][ppos+1] = true;
            
            for(int i = spos; i >= 0; i--){
                if(str[i] == pat[ppos-1] || pat[ppos-1] == '?' || pat[ppos-1] == '*'){
                    if(findMatch(str, pat, i-1, ppos-2))
                        return cache[spos+1][ppos+1] = true;
                }
            }

            return cache[spos+1][ppos+1] = false;
        }else{
            if(spos < 0) return false;
            return cache[spos+1][ppos+1] = str[spos] == pat[ppos] && findMatch(str, pat, spos-1, ppos-1);
        }
    }
    
    bool isMatch(string s, string p) {
        cache.resize(s.length()+2, vector<int>(p.length()+2, -1));
        return findMatch(s, p, s.length()-1, p.length()-1);
    }
};