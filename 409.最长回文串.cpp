/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]]++;
        }
        bool single = false;
        int sum = 0;
        for (const auto& kv : m) {
            if (kv.second % 2 == 0) {
                sum += kv.second;
            } else {
                sum += kv.second - 1;
                single = true;
            }
        }
        return sum + single;
    }
};
// @lc code=end

