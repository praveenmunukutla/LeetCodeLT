class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string,vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for(auto it = map.begin(); it != map.end(); ++it){
            vector<string> s = it->second;
            result.push_back(s);
        }
        return result;
    }
};