#define abs(a,b) ((a)>(b)?(a-b):(b-a))
class Solution {
public:
    double myPowUtil(double x, int n){
        if(n == 0)
             return 1;
        
        double val = myPowUtil(x, n/2);
        int eoro = n%2;
        if(eoro == 0)
            return val * val;
        return val*val*x;
    }
    
    double myPow(double x, int n) {
        if(n < 0 && n != INT_MIN)
            return (double)1.0/myPowUtil(x, n*-1);
        else if(n < 0 && n == INT_MIN)
            return (double)1.0/(x*myPowUtil(x, INT_MAX));
        return myPowUtil(x, n);
    }
};