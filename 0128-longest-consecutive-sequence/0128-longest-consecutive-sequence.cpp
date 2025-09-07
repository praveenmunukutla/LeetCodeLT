class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    vector<int> vec = move(nums);
    unordered_map<int, int> map;
	for (int i = 0; i < vec.size(); i++)
		map[vec[i]] = vec[i];

	queue<int> q;
	int ans = 0;
	while (1) {
		if (map.size() == 0)
			break;
		auto it = next(map.begin(), 0);
		int ele = it->first;
		q.push(ele);
		map.erase(map[ele]);
		int count = 0;
		while (!q.empty()) {
			int val = q.front(); q.pop();
			count++;
			if (map.find(val + 1) != map.end()) {
				q.push(val + 1);
				map.erase(map[val + 1]);
			}
			if (map.find(val - 1) != map.end()) {
				q.push(val - 1);
				map.erase(map[val - 1]);
			}
		}
		ans = count > ans ? count : ans;
	}

	return ans;  
    }
};