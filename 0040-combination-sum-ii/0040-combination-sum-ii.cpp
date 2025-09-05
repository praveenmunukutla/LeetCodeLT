class Solution {
	vector<vector<int>> result;
	vector<int> mcandidates;
	vector<int> temp;
public:
	void combinationSum2Util(int index, int target){
		if (target == 0){
			result.push_back(temp);
			return;
		}

		if (index >= mcandidates.size() || target-mcandidates[index] < 0)
			return;

		//consider the number;
		temp.push_back(mcandidates[index]);
		combinationSum2Util(index + 1, target - mcandidates[index]);
		temp.pop_back();

		//dont consider the number;
		//when we are not considering the number
		//ignore the duplicate number
		// 1 1 1 1 2 3 4
		// ^
		//         ^     <= next process element should be 2
		// we are zeroth index, now we are not considering 1 in the result
		// so next number which should be included in the result is 2, so
		// move the index to 4.
		while(index < mcandidates.size() - 1 && mcandidates[index] == mcandidates[index+1])
            index++;

		combinationSum2Util(index + 1, target);
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		mcandidates = move(candidates);
		sort(mcandidates.begin(), mcandidates.end());
		combinationSum2Util(0, target);
		return move(result);
	}
};