class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<int>& current,
                   vector<vector<int>>& result) {
        
        if (i == nums.size()) {
            result.push_back(current);
            return;
        }

        // Include
        current.push_back(nums[i]);
        backtrack(nums, i + 1, current, result);

        // Backtrack
        current.pop_back();

        // Exclude
        backtrack(nums, i + 1, current, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(nums, 0, current, result);

        return result;
    }
};