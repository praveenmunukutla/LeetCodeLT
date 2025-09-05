class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int maxLen = INT_MIN;
        int left = 0, right = 0;
        for(;right < s.length(); right++){

            while(uset.find(s[right]) != uset.end()){
                uset.erase(s[left]);
                left++;
            }

            uset.insert(s[right]);
            maxLen = max(maxLen, right-left+1);
        }

        return maxLen == INT_MIN ? 0 : maxLen;
    }
};