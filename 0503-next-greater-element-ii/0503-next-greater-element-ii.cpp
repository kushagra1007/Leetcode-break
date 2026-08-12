#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;   // stores indices

        // Traverse the array twice (circularly) from the back
        for (int i = 2 * n - 1; i >= 0; i--) {
            // Pop elements smaller than or equal to current
            while (s.size() > 0 && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }

            // If stack is empty, no greater element found; else top is the answer
            ans[i % n] = s.empty() ? -1 : nums[s.top()];

            // Push current index for future comparisons
            s.push(i % n);
        }

        return ans;
    }
};