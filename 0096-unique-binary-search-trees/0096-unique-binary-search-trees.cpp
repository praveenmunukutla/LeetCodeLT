class Solution {
    vector<unsigned long long int> cache;
public:
    int catalan(unsigned long long int n){
        if(n <= 1)
            return 1;
        
        if(cache[n] != 0)
            return cache[n];
        
        unsigned long long int res = 0;
        for(int i = 0; i < n; i++)
            res += catalan(i)*catalan(n-i-1);
        return cache[n] = res;
    }
    
    int numTrees(int n) {
        cache.resize(n+1, 0);
        return catalan(n);
    }
};