const vector<int> no{ 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
const vector<string> nstr{ "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

class Solution {
public:
	int getDivisor(int n){
		for (int i = 12; i >= 0; i--){
			if (no[i] <= n)
				return i;
		}
		return 0;
	}

	string intToRoman(int num) {
		string ans;
		while (num){
			int index = getDivisor(num);
			int quo = num / no[index];
			int rem = num % no[index];
			while(quo--){
				ans += nstr[index];
			}
			if (rem == 0)
				break;
			num = rem;
		}
		return move(ans);
	}
};