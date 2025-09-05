class Solution {
public:
    int reverse(int x) {
                int rev = 0;
        
        while(x)
        {
            rev = rev*10 + x%10;
            x   = x/10;
            
            if(x && (rev > INT_MAX/10 || rev < INT_MIN/10))
                return 0;
        }

        return rev;
    }
};