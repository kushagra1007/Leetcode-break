class Solution {
public:

    void getAllCombinations(vector<int>& arr, int idx, int target, vector<vector<int>>& ans, vector<int>& combination) {

        // Target achieved
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        // No more elements
        if (idx == arr.size() || target < 0) {
            return;
        }

        for (int i = idx; i < arr.size(); i++) {

            // Skip duplicate elements at the same recursion level
            if (i > idx && arr[i] == arr[i - 1])
                continue;

            // Since array is sorted, no need to continue
            if (arr[i] > target)
                break;

            // Choose
            combination.push_back(arr[i]);

            // Move to i + 1 because every element can be used only once
            getAllCombinations(arr, i + 1, target - arr[i], ans, combination);

            // Backtracking
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> combination;

        getAllCombinations(candidates, 0, target, ans, combination);

        return ans;
    }
};