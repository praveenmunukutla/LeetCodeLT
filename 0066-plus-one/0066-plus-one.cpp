class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0)
			return vector<int>{};

		vector<int> result;
		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; i--){
			int val = digits[i] + carry;
			if (val >= 10)
				carry = 1;
			else
				carry = 0;
			val = val % 10;
			result.push_back(val);
		}
		if (carry)
			result.push_back(1);

		reverse(result.begin(), result.end());
		return move(result);
	}
};