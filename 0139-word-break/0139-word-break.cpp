class Solution {
	unordered_map<string, bool> map;
	unordered_map<string, bool> cache;
public:
	bool wordBreakUtil(string s){
		int size = s.length();
		if (size == 0) return true;

		if (cache.find(s) != cache.end())
			return cache[s];

		for (int i = 1; i <= size; i++){
			if (map[s.substr(0, i)] && wordBreakUtil(s.substr(i, size - i))){
				cache[s] = true;
				return true;
			}
		}

		cache[s] = false;
		return false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		for (int i = 0; i < wordDict.size(); i++)
			map[wordDict[i]] = true;
		return wordBreakUtil(s);
	}
};