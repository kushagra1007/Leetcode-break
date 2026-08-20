class Solution {
public:
    bool isValid(vector<int> &arr, int n, int m, long long maxAllowedPages) {
        int student = 1;
        long long pages = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > maxAllowedPages)
                return false;

            if (pages + arr[i] <= maxAllowedPages)
                pages += arr[i];
            else {
                student++;
                pages = arr[i];
            }
        }

        return student <= m;
    }

    int findPages(vector<int> &arr, int m) {
        int n = arr.size();
        if (m > n) return -1;

        long long sum = 0;
        for (int x : arr) sum += x;

        long long st = *max_element(arr.begin(), arr.end());
        long long end = sum;
        long long ans = -1;

        while (st <= end) {
            long long mid = st + (end - st) / 2;

            if (isValid(arr, n, m, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return (int)ans;
    }
};