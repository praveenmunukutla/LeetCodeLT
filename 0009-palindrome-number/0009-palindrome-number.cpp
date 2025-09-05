class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        int d = 0;
		long int x1 = 0;
		long int xc = x;
        while(x){
            d = x % 10;
            x1 = x1 * 10 + d;
			if(x1 > INT_MAX)
				return false;
            x = x / 10;
        }
        
        return xc == x1;
    }
};