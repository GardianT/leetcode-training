/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1 = 0;
        int l2 = 0;
        while (l2 < t.size()) {
            if (l1 < s.size() && s[l1] == t[l2]) {
                l1++;
            }
            l2++;
        }
        return l1 == s.size();
    }
};
// @lc code=end

