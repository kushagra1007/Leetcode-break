class Solution {
public:
    void getAllCombinations(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin) {
        if(tar == 0) {
            ans.push_back(combin);
            return;
        }

        if(idx == arr.size() || tar < 0) {
            return;
        }

        // Take
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx + 1, tar - arr[idx], ans, combin);

        // Backtracking
        combin.pop_back();

        // Not Take
        int nextIdx = idx + 1;

        // Skip duplicate elements
        while(nextIdx < arr.size() && arr[nextIdx] == arr[idx]) {
            nextIdx++;
        }

        getAllCombinations(arr, nextIdx, tar, ans, combin);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> combine;

        getAllCombinations(candidates, 0, target, ans, combine);

        return ans;
    }
};