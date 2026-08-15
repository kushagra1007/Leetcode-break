class Solution {
public:
    void printSubsets(vector<int>& arr, vector<int>& ans, int i,
                      vector<vector<int>>& result) {

        // Base case
        if (i == arr.size()) {
            result.push_back(ans);
            return;
        }

        // Include arr[i]
        ans.push_back(arr[i]);
        printSubsets(arr, ans, i + 1, result);

        // Backtrack
        ans.pop_back();

        int idx = i+1;
        while(idx<arr.size() && arr[idx] == arr[idx-1]) idx++;
        // Exclude arr[i]
        printSubsets(arr, ans, idx, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ans;

        printSubsets(nums, ans, 0, result);

        return result;
    }
};