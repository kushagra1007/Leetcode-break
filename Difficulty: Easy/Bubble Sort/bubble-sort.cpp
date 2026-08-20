class Solution {
public:
    void bubble(vector<int>& arr, int n) {

        // Base case
        if (n == 1) {
            return;
        }

        // One pass: largest element goes to the end
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }

        // Sort remaining elements
        bubble(arr, n - 1);
    }
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        bubble(arr, n);
    }
};