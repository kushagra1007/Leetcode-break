class Solution {
public:
    void solve(vector<int>& candidates, int idx, int target,
               vector<int>& current, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Since candidates are sorted
            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            // i, not i+1, because the same element can be reused
            solve(candidates, i, target - candidates[i], current, ans);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, 0, target, current, ans);

        return ans;
    }
};