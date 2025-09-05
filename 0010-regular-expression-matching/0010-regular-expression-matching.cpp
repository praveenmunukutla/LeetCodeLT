class Solution {
public:
bool findRegxMatch(string& str, string& pat, int spos, int ppos){
	if (spos == -1 && ppos == -1)
		return true;
    
	if (spos < -1 || ppos == -1)
		return false;
    
	if (pat[ppos] == '.')
		return findRegxMatch(str, pat, spos - 1, ppos - 1);
	else if (pat[ppos] == '*'){
		if (findRegxMatch(str, pat, spos, ppos - 2))
			return true;

		for (int i = spos; i >= 0; i--){
			if (str[i] == pat[ppos - 1] || pat[ppos - 1] == '.'){
				if (findRegxMatch(str, pat, i - 1, ppos - 2))
					return true;
			}
			else 
				break;
		}

		return false;
	}
	else {
        if(spos < 0)
            return false;
		return str[spos] == pat[ppos] && findRegxMatch(str, pat, spos - 1, ppos - 1);
	}
}

bool isMatch(string str, string pat){
	return findRegxMatch(str, pat, str.length() - 1, pat.length() - 1);
}
};