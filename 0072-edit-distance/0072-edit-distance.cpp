class Solution {
    string str1, str2;
    vector<vector<int>> cache;
public:

    int minDistanceUtil(int len1, int len2){
        if(len1 == 0)
            return len2;
        if(len2 == 0)
            return len1;
        
        if(str1[len1-1] == str2[len2-1])
            return minDistanceUtil(len1-1, len2-1);
        
        if(cache[len1][len2] != -1)
            return cache[len1][len2];
        
        int v1 = minDistanceUtil(len1-1, len2-1);//replace
        int v2 = minDistanceUtil(len1-1, len2);//insert
        int v3 = minDistanceUtil(len1, len2-1);//delete
            
        return cache[len1][len2] = (min(min(v1, v2), v3))+1;
    }
    
    int minDistance(string word1, string word2) {
        str1 = move(word1);
        str2 = move(word2);
        cache.resize(str1.length()+1, vector<int>(str2.length()+1, -1));
        return minDistanceUtil(str1.length(), str2.length());
    }
};