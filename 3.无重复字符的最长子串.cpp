/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<char, int> m;
        int res = 0;
        int last_idx = -1;
        for (int i = 0; i < s.size(); ++i) {
            auto chr = s[i];
            if (m.find(chr) != m.end()) {
                last_idx = max(last_idx, m[chr]);
            }
            res = max(res, i - last_idx);
            m[chr] = i;
        }
        return res;
    }
};
// @lc code=end

