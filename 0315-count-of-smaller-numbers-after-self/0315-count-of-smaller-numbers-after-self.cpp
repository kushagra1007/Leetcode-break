class Solution {
public:
    vector<int> counts;

    void mergeSortCount(vector<pair<int,int>>& arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSortCount(arr, left, mid);
        mergeSortCount(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    void merge(vector<pair<int,int>>& arr, int left, int mid, int right) {
        vector<pair<int,int>> merged;
        int i = left, j = mid + 1;
        int rightCount = 0;

        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                rightCount++;
                merged.push_back(arr[j]);
                j++;
            } else {
                // arr[i].first <= arr[j].first, take from left
                counts[arr[i].second] += rightCount;
                merged.push_back(arr[i]);
                i++;
            }
        } 

        // leftover left elements: all of rightCount applies (right half exhausted)
        while (i <= mid) {
            counts[arr[i].second] += rightCount;
            merged.push_back(arr[i]);
            i++;
        }

        // leftover right elements: just copy, no counting needed
        while (j <= right) {
            merged.push_back(arr[j]);
            j++;
        }

        // copy merged back into original array range
        for (int k = left; k <= right; k++) {
            arr[k] = merged[k - left];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        counts.assign(n, 0);

        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        mergeSortCount(arr, 0, n - 1);

        return counts;
    }
};