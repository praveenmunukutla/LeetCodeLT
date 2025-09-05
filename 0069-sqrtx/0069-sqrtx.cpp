class Solution {
public:
	int mySqrt(int x) {
		int floor = 0;

		int left = 1, right = x;
		while (left <= right) {
			int mid = ((right - left) / 2) + left;
			if (mid == x / mid)
				return mid;
			if (mid < x / mid) {
				floor = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
		return floor;
	}
};