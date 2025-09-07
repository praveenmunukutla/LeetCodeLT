struct wordlen{
	int len;
	string word;
	wordlen(int l, string w) :len(l), word(w){}
};

class Solution {
	queue<wordlen> que;
public:
	bool isAdjacent(string& s1, string& s2){
		int l1 = s1.length();
		int l2 = s2.length();
		if (l1 != l2)return false;
		int count = 0;
		for (int i = 0; i < l1; i++){
			if (s1[i] != s2[i])
				count++;
			if (count > 1) return false;
		}
		return (count == 1);
	}

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		vector<bool> visited;
		visited.resize(wordList.size(), false);

		que.push(wordlen(1, beginWord));
		while (!que.empty()){
			wordlen w = que.front();
			que.pop();
			for (int i = 0; i < wordList.size(); i++){
				string &tstr = wordList[i];
				if (visited[i] == false && isAdjacent(w.word, tstr)){
					if (tstr == endWord)
						return w.len + 1;
					que.push(wordlen(w.len+1, tstr));
					visited[i] = true;
				}
			}
		}
		return 0;
	}
};