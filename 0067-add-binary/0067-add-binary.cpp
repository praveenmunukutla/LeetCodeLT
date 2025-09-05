class Solution {
public:
	string addBinary(string a, string b) {
		int i = a.length()-1;
		int j = b.length()-1;
		int carry = 0;
		string ans;
		while (i>=0 && j>=0){
			int val = a[i] - '0' + b[j] - '0' + carry;
			carry = 0;
			if (val == 0 || val == 1)
				ans += (val + '0');
			else if (val == 2){
				ans += '0';
				carry = 1;
			}
			else if (val == 3){
				ans += '1';
				carry = 1;
			}
			i--;
			j--;
		}

		while (i>=0){
			int val = a[i] - '0' + carry;
			carry = 0;
			if (val == 0 || val == 1)
				ans += (val + '0');
			else if (val == 2){
				ans += '0';
				carry = 1;
			}
			else if (val == 3){
				ans += '1';
				carry = 1;
			}
			i--;
		}

		while (j>=0){
			int val = b[j] - '0' + carry;
			carry = 0;
			if (val == 0 || val == 1)
				ans += (val + '0');
			else if (val == 2){
				ans += '0';
				carry = 1;
			}
			else if (val == 3){
				ans += '1';
				carry = 1;
			}
			j--;
		}

		if (carry == 1)
			ans += '1';

		reverse(ans.begin(), ans.end());
		return ans;
	}
};
