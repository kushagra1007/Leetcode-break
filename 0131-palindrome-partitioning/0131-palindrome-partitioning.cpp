class Solution {
public:
    vector<vector<string>> result;
    vector<string> current;

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void backtrack(string& s, int start) {
        // Base case: reached end of string, current partition is complete
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // choose
                current.push_back(s.substr(start, end - start + 1));

                // explore
                backtrack(s, end + 1);

                // un-choose (backtrack)
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }
};