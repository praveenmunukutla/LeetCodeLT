#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define ABS(a,b) ((a)>(b)?(a-b):(b-a))

class Solution {
	vector<int> lmax;
	vector<int> rmax;
	int hsize;
public:
	int trap(vector<int>& height) {
		hsize = height.size();
		if (hsize == 0)
			return 0;

		lmax.push_back(height[0]);
		for (int i = 1; i < hsize; i++){
			int mval = max(height[i], lmax[i - 1]);
			lmax.push_back(mval);
		}

		rmax.resize(hsize, 0);
		rmax[hsize - 1] = height[hsize - 1];
		for (int i = hsize - 2; i >= 0; i--){
			int mval = max(height[i], rmax[i + 1]);
			rmax[i] = mval;
		}
		
		int ans = 0;
		for (int i = 0; i < hsize; i++){
			int mval = min(lmax[i], rmax[i]);
			ans += ABS(height[i] , mval);
		}
		return ans;
	}
};