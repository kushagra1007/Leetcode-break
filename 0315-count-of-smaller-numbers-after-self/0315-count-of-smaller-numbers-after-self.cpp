class Solution {
public:
    vector<int> counts;
    vector<pair<int, int>> temp;

    void mergeSort(vector<pair<int, int>>& arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }

    void merge(vector<pair<int, int>>& arr, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int k = left;
        int rightCount = 0;

        while (i <= mid && j <= right) {

            if (arr[j].first < arr[i].first) {
                // This right element is smaller than arr[i]
                rightCount++;
                temp[k++] = arr[j++];
            }
            else {
                // All previously selected right elements
                // are smaller than arr[i]
                counts[arr[i].second] += rightCount;
                temp[k++] = arr[i++];
            }
        }

        // Remaining left elements
        while (i <= mid) {
            counts[arr[i].second] += rightCount;
            temp[k++] = arr[i++];
        }

        // Remaining right elements
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy sorted range back
        for (int p = left; p <= right; p++) {
            arr[p] = temp[p];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        counts.assign(n, 0);
        temp.resize(n);

        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        mergeSort(arr, 0, n - 1);

        return counts;
    }
};