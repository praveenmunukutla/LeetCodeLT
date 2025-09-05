class Solution {
    vector<int> cache;
public:
    int climbStairsUtil(int n) {
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        if(cache[n] != -1)
            return cache[n];
        return cache[n] = climbStairsUtil(n-1) + climbStairsUtil(n-2);
    }
    
    int climbStairs(int n){
        cache.resize(n+10, -1);
        return climbStairsUtil(n);
    }
};