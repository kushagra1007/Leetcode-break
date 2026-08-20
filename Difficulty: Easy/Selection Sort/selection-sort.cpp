class Solution {
public:
    void selectionSortRecursive(vector<int>& arr, int i) {

        // Base case
        if (i >= arr.size() - 1) {
            return;
        }

        // Find smallest element from i to end
        int smallestIdx = i;

        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[smallestIdx]) {
                smallestIdx = j;
            }
        }

        // Place smallest element at index i
        swap(arr[i], arr[smallestIdx]);

        // Recursively sort remaining array
        selectionSortRecursive(arr, i + 1);
    }
    void selectionSort(vector<int>& arr) {
        selectionSortRecursive(arr, 0);
    }
};