class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1e9 + 7;

        // Prefix sums: prefix[i] = sum(nums[0..i-1])
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Nearest smaller to the left (exclusive boundary index)
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Nearest smaller to the right (exclusive boundary index)
        vector<int> right(n, n);
        while (!st.empty()) st.pop(); // clear stack for reuse
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long best = 0;
        for (int i = 0; i < n; i++) {
            long long rangeSum = prefix[right[i]] - prefix[left[i] + 1];
            best = max(best, (long long)nums[i] * rangeSum);
        }

        return (int)(best % MOD);
    }
};