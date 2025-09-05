class Solution {
public:
	int divide(int dividend, int divisor) {
		if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;
        long dvd = labs(dividend), dvs = labs(divisor);
        long ans = 0;
        while(dvs <= dvd){
            long temp = dvs, m = 1;
            while(temp << 1 <= dvd){
                temp = temp << 1;
                m = m << 1;
            }
            dvd -= temp;
            ans += m;
        }
        return ans * sign;
	}
};